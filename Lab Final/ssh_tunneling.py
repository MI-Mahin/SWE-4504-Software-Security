import socket
import threading
import paramiko

ssh_host = '192.168.180.245'
ssh_user = 'mahin'
ssh_password = '12111'
web_server_host = '127.0.0.1'
web_server_port = 8080
local_port = 9090

## creating the ssh client
client = paramiko.SSHClient()
client.load_system_host_keys()
client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

try:
    client.connect(hostname=ssh_host, username=ssh_user, password=ssh_password)
    transport = client.get_transport()

    def forwarder(local_socket, remote_host, remote_port):
        remote_socket = transport.open_channel('direct-tcpip', (remote_host, remote_port), local_socket.getpeername())
        while True:
            try:
                data = local_socket.recv(1024)
                if len(data) == 0:
                    break
                remote_socket.send(data)
            except Exception:
                break
        
        local_socket.close()
        remote_socket.close()


    ## listen on the local port
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('127.0.0.1', local_port))
    server.listen(5)

    print(f'[*] Listening on {web_server_host}:{web_server_port} and forwarding to {ssh_host}:{local_port}')
    while True:
        local_socket, addr = server.accept()
        print(f'[+] Accepted connection from {addr[0]}:{addr[1]}')
        print(f'[+] Forwarding connection from {addr[0]}:{addr[1]} to {web_server_host}:{web_server_port} via SSH {ssh_host}:{local_port}')
        thread = threading.Thread(target=forwarder, args=(local_socket, web_server_host, web_server_port))
        thread.start()

except Exception as e:
    print(f'[-] Error: {e}')

finally:
    client.close()