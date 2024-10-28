# 🚀 Service Inspector
A powerful cybersecurity tool designed to inspect and monitor services running on Windows machines. This script retrieves configuration details, extracts process information, and monitors network connections of specific services.

# 🌟 Features
* 🛠️ Service Configuration Analysis
Extracts detailed configuration info, such as start type, binary path, and service dependencies.

* 🔍 Process ID (PID) Extraction
Automatically retrieves the PID of the selected service for deeper analysis.

* 🌐 Network Connection Mapping
Monitors network connections tied to the service by analyzing open connections based on the PID.

* ⚡ Fast & Automated
Speeds up service and process monitoring for incident response and post-exploitation analysis.

# 📂 Installation & Usage
## Prerequisites
+ Operating System: ![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
+ C Compiler: GCC for Windows (e.g., MinGW), or any compatible compiler.

# How to Install
1: Clone this repository:
```
git clone https://github.com/blackmummya/Service_Inspector.git
```
2: Navigate to the directory:
```
cd service_inspector
```
3: Compile the script:
```
gcc -o si service_inspector.c
```

# How to Run
1: Execute the compiled script:
```
si
```
2: Enter the service name when prompted.
For example:
```
[+] Enter Service Name: wuauserv
```

# 🔥 Example Output
```
[+] Enter Service Name: wuauserv
[+] Filtering service configuration information
SERVICE_NAME: wuauserv
        TYPE               : 20  WIN32_SHARE_PROCESS
        START_TYPE         : 2   AUTO_START
        ERROR_CONTROL      : 1   NORMAL
        BINARY_PATH_NAME   : C:\Windows\system32\svchost.exe -k netsvcs -p
        DISPLAY_NAME       : Windows Update
PID : 1234
Active Network Connections:
  TCP    0.0.0.0:135     123.123.123.123:12345  ESTABLISHED
```

# 🛡️ Cybersecurity Use Cases
* Incident Response
Quickly identify suspicious services and check their network activity during a security investigation.

* Post-Exploitation
Enumerate system services after gaining access, aiding in privilege escalation and lateral movement.

* Service Audits
Verify service configurations and network connections to ensure they align with security policies.

# 🎯 Contributing
If you'd like to contribute to Service Inspector, feel free to fork the repository and submit a pull request. Issues and feature requests are welcome!
