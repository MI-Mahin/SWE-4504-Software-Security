import subprocess
import ipaddress
import socket
import platform
import concurrent.futures

# Function to ping a host
def ping_host(ip):
    try:
        if platform.system().lower() == "windows":
            command = ['ping', '-n', '1', '-w', '500', str(ip)]  
        else:
            command = ['ping', '-c', '1', '-W', '1', str(ip)]  
        output = subprocess.run(
            command,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            timeout=2
        )
        return output.returncode == 0  
    except (subprocess.TimeoutExpired, subprocess.CalledProcessError):
        return False

# Function to get the local subnet dynamically
def get_subnet():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        s.connect(('8.8.8.8', 80))  
        local_ip = s.getsockname()[0]
    finally:
        s.close()
    
    network = ipaddress.IPv4Network(f"{local_ip}/24", strict=False)  
    return network

# Function to scan subnet for active hosts
def discover_hosts(network):
    active_hosts = []
    
    print(f"\nScanning subnet: {network}")
    print(f"Network Address: {network.network_address}")
    print(f"Broadcast Address: {network.broadcast_address}")
    
    with concurrent.futures.ThreadPoolExecutor(max_workers=50) as executor:
        futures = {
            executor.submit(ping_host, ip): ip 
            for ip in network.hosts()
        }
        
        for future in concurrent.futures.as_completed(futures):
            ip = futures[future]
            try:
                if future.result():
                    try:
                        hostname = socket.gethostbyaddr(str(ip))[0]  
                        active_hosts.append((str(ip), hostname))
                        print(f"Active Host: {ip} (Hostname: {hostname})")
                    except (socket.herror, socket.gaierror):
                        active_hosts.append((str(ip), "N/A"))
                        print(f"Active Host: {ip} (Hostname: N/A)")
            except Exception as exc:
                print(f"{ip} generated an exception: {exc}")
    
    return active_hosts

# Main function
def main():
    subnet = get_subnet()  
    
    print("\nStarting host discovery...")
    active_hosts = discover_hosts(subnet)
    
    print("\n**Host Discovery Summary**")
    print(f"Total Active Hosts: {len(active_hosts)}")
    
    if active_hosts:
        print("\n **Detailed Active Hosts**")
        for ip, hostname in active_hosts:
            print(f"IP: {ip}, Hostname: {hostname}")
    else:
        print("No active hosts found!")

if __name__ == "__main__":
    main()
