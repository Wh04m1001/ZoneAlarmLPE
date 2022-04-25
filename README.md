# ZoneAlarmLPE
Exploit for LPE in ZoneAlarm Antivirus/Firewall.
Combination of weak permissions in **C:\ProgramData\CheckPoint\ZoneAlaram\Data**  and self-protection bypass (self-protection driver failed to protect sensitive files from modification when file is accessed over UNC path) leads to LPE allowing any local user  to elevate privileges to SYSTEM account.



https://user-images.githubusercontent.com/44291883/165168606-8f30dd07-2400-41af-9fa3-bbd1cb55954d.mp4

