# ZoneAlarmLPE
Exploit for LPE in ZoneAlarm Antivirus/Firewall.
Combination of weak permissions in **C:\ProgramData\CheckPoint\ZoneAlaram\Data**  and self-protection bypass (self-protection driver failed to protect sensitive files from modification when file is accessed over UNC path) leads to LPE allowing any local user  to elevate privileges to SYSTEM account.

