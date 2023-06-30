# Born2BeRoot
- [Install Guide](#install-guide)
- [LVM](#what-is-lvm)
- [apt vs aptitude](#apt-vs-aptitude)
- [SElinux vs AppArmor](#selinux-vs-apparmor)
- [SSH](#ssh)
- [UFW](#ufw)
- [PASSWORD POLICY](#password-policy)
- [GROUP](#group)
- [SUDO](#sudo)
- [monitoring.sh](#monitoringsh)

## Install Guide
![](img/1.png)
![](img/2.png)
![](img/3.png)
![](img/4.png)
![](img/5.png)
![](img/6.png)
![](img/7.png)
![](img/8.png)
![](img/9.png)
![](img/10.png)
![](img/11.png)
![](img/12.png)
![](img/13.png)
![](img/14.png)
![](img/15.png)
![](img/16.png)
![](img/17.png)
![](img/18.png)
![](img/19.png)
![](img/20.png)
![](img/21.png)
![](img/22.png)
![](img/23.png)
![](img/24.png)
![](img/25.png)
![](img/26.png)
![](img/27.png)
![](img/28.png)
![](img/29.png)
![](img/30.png)
![](img/31.png)
![](img/32.png)
![](img/33.png)
![](img/34.png)
![](img/35.png)
![](img/36.png)
![](img/37.png)
![](img/38.png)
![](img/39.png)
![](img/40.png)

## What is LVM
- [What is LVM](https://mamu2830.blogspot.com/2019/12/lvmpv-vg-lv-pe-lvm.html)
- [LVM Concepts](https://wiseworld.tistory.com/32)

## apt vs aptitude
- [What is APT and Aptitude](https://www.tecmint.com/difference-between-apt-and-aptitude/)

## SElinux vs AppArmor
- [Compare two Linux security modules: SELinux vs AppArmor](https://www.techtarget.com/searchdatacenter/tip/Compare-two-Linux-security-modules-SELinux-vs-AppArmor)
- [AppArmor vs. SELinux](https://phoenixnap.com/kb/apparmor-vs-selinux)

## SSH
```bash
apt-get install openssh-server
vim /etc/ssh/sshd_config
	#Port 22 -> Port 4242
	#PermitRootLogin no
systemctl restart ssh
systemctl status ssh
hostnamectl
hostname -I
vim /etc/hostname
ssh seunan@<MAC_IP> -p <HOST_PORT>
cat /etc/ssh/sshd_config | grep "PermitRootLogin"
```
- [What is SSH](https://www.freecodecamp.org/news/ssh-meaning-in-linux/#:~:text=Secure%20Shell%20(SSH)%20is%20a,remote%20administration%20and%20file%20transfer.)
- [Enable the SSH server](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=jodi999&logNo=221334854192)
- [Configure the /etc/ssh/sshd_config file](https://www.linuxtopia.org/online_books/linux_system_administration/securing_and_optimizing_linux/chap15sec122.html)
- [SSH wiki](https://zetawiki.com/wiki/%EB%A6%AC%EB%88%85%EC%8A%A4_sshd_%EC%9E%AC%EC%8B%9C%EC%9E%91)
- [Change the Default SSH port](https://www.ionos.com/help/server-cloud-infrastructure/getting-started/important-security-information-for-your-server/changing-the-default-ssh-port/)
- [hostnamectl](https://zetawiki.com/wiki/%EB%A6%AC%EB%88%85%EC%8A%A4_%ED%98%B8%EC%8A%A4%ED%8A%B8%EB%AA%85_%EB%B3%80%EA%B2%BD_hostnamectl_set-hostname)
- [Port Forwarding1](https://nsrc.org/workshops/2014/sanog23-virtualization/raw-attachment/wiki/Agenda/ex-virtualbox-portforward-ssh.htm)
- [Port Forwarding2](https://www.activecountermeasures.com/port-forwarding-with-virtualbox/)
- [Port Forwarding3](https://www.nemonein.xyz/2020/01/3048/)
- [Port Forwarding4](https://m.blog.naver.com/yexx/221996230014)
## UFW
```bash
apt-get install ufw
ufw status verbose
ufw enable
ufw default deny
ufw allow 4242
cat /etc/ufw/user.rules
ufw status numbered
ufw delete <rule number>
```
- [UFW setting](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=jodi999&logNo=221409997866)
- [UFW status](https://linuxhint.com/ufw_status/)
- [Debian wiki](https://wiki.debian.org/Uncomplicated%20Firewall%20%28ufw%29)

## PASSWORD POLICY
```bash
chage -l
chage -M
chage -m 2 -M 30 -W 7
passwd -e user

vi /etc/login.defs
PASS_MAX_DAYS 30
PASS_MIN_DATS 2
PASS_WARN_AGE 7

apt-get install libpam-pwquality
vi /etc/pam.d/common-password
retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username enforce_for_root difok=7

passwd -e <username>
```
- [Password policy1](https://techpicnic.tistory.com/506)
- [Password policy2](https://www.haedongg.net/2020/08/28/linux-%ED%8C%A8%EC%8A%A4%EC%9B%8C%EB%93%9C-%EA%B4%80%EB%A0%A8-%EC%A0%95%EC%B1%85-%EC%84%A4%EC%A0%95/)
- [man PAM_PWQUALITY](https://manpages.debian.org/stretch/libpam-pwquality/pam_pwquality.8.en.html)
- [Managing Password Complexity in Linux](https://www.baeldung.com/linux/password-complexity)
## GROUP
- [group](https://www.manualfactory.net/13414)
- [Verify user groups](https://goni9071.tistory.com/68)
## SUDO
```bash
apt-get install sudo
visudo sudoers
	Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
	Defaults	passwd_tries=3
	Defaults	badpass_message=""
	Defaults	authfail_message=""
	Defaults	log_input, log_output
	Defaults	iolog_dir="/var/log/sudo/"
	Defaults	requiretty
cd /var/log/sudo
usermod -aG sudo seunan
```
- [debian wiki](https://wiki.debian.org/sudo/)
- [Add User to Sudoers](https://www.cloudpanel.io/tutorial/how-to-add-user-to-sudoers-in-debian/)
- [Configure Sudoers](https://ko.linux-console.net/?p=1985#gsc.tab=0)
- [man sudoers](https://man.freebsd.org/cgi/man.cgi?query=sudoers&apropos=0&sektion=0&manpath=FreeBSD+13.0-RELEASE+and+Ports&arch=default&format=html)

## monitoring.sh
- [The architecture of your operating system and its kernel version](https://www.cyberciti.biz/faq/find-print-linux-unix-kernel-version/)
- [The number of physical processors](https://www.cyberciti.biz/faq/check-how-many-cpus-are-there-in-linux-system/)
- [The number of virtual processors](https://webhostinggeeks.com/howto/how-to-display-the-number-of-processors-vcpu-on-linux-vps/)
- [The current available RAM on your server and its utilization rate as a percentage](https://www.2daygeek.com/linux-check-cpu-memory-swap-utilization-percentage/)
- [The current available memory on your server and its utilization rate as a percentage](https://www.2daygeek.com/linux-check-cpu-memory-swap-utilization-percentage/)
- [The current utilization rate of your processors as a percentage](https://www.baeldung.com/linux/get-cpu-usage)
- [The date and time of the last reboot](https://www.cyberciti.biz/tips/linux-last-reboot-time-and-date-find-out.html)
- [Whether LVM is active or not](https://askubuntu.com/questions/202613/how-do-i-check-whether-i-am-using-lvm)
- [The number of active connections](https://serverfault.com/questions/421310/check-the-number-of-active-connections-on-port-80)
- [The number of users using the server](https://www.computerhope.com/issues/ch001649.htm)
- [The IPv4 address of your server and its MAC (Media Access Control) address](https://www.howtouselinux.com/post/linux-command-get-mac-address-in-linux)
- [The number of commands executed with the sudo program](https://unix.stackexchange.com/questions/167935/details-about-sudo-commands-executed-by-all-user)
