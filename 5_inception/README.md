# inception

## Mendatory part

[**Container to implement:**](#container-to-implement)
- [ ] A Docker container that contains NGINX with TLSv1.2 or TLSv1.3 only
- [ ] NGINX container must be the only entrypoint into your infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3 protocol.
- [ ] A Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx.
- [ ] A Docker container that contains MariaDB only without nginx.

[**Volumes to implement:**](#volumes-to-implement)
- [ ] A volume that contains your WordPress database
- [ ] A second volume that contains your WordPress website files.

[**Network to implement:**](#network-to-implement)
- [ ] A docker-network that establishes the connection between your containers.

[**Things to study:**](#things-to-study)
- [x] [What is docker?](https://github.com/seungwonme/DevOps/tree/main/docker)
- [x] [Alpine Linux vs Debian](https://stackshare.io/stackups/alpine-linux-vs-debian)
- [ ] how daemons work and whether it’s a good idea to use them or not?
- [ ] PID 1 and the best practices for writing Dockerfiles.

### Container to implement

#### A Docker container that contains NGINX with TLSv1.2 or TLSv1.3 only
> NGINX container must be the only entrypoint into your infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3 protocol.
- [Configuring HTTPS servers](https://nginx.org/en/docs/http/configuring_https_servers.html)
- [How To Configure Nginx to use TLS 1.2 / 1.3 only](https://www.cyberciti.biz/faq/configure-nginx-to-use-only-tls-1-2-and-1-3/)

**NGINX**
- [Nginx란 무엇인가? : 네이버 블로그](https://blog.naver.com/gi_balja/223028077537)
- [Nginx란 무엇인가?](https://dkswnkk.tistory.com/513)
- [Forward Proxy와 Reverse Proxy](https://dkswnkk.tistory.com/506?category=551275)

**TLS**
- [TLS의 정의 및 이해와 TLS1.2과 TLS1.3의 차이](https://sym312.tistory.com/14)
- [TLS 1.3 특징, 기존 TLS 버전과의 차이점](https://blog.naver.com/PostView.nhn?blogId=cr0sscert&logNo=221706613801)
- [[HTTPS] SSL/TLS 보안 프로토콜 이해하기( TLS 1.2 / TLS 1.3 )](https://aday7.tistory.com/entry/HTTPS-SSLTLS-%EB%B3%B4%EC%95%88-%ED%94%84%EB%A1%9C%ED%86%A0%EC%BD%9C-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-TLS-12-TLS-13)
- [SSL/TLS의 이해와 TLS 1.3으로 업그레이드해야 하는 이유 - ITWorld Korea](https://www.itworld.co.kr/news/113007)

#### A Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx.

#### A Docker container that contains MariaDB only without nginx.

### Volumes to implement
> Your volumes will be available in the /home/login/data folder of the host machine using Docker.

**A volume that contains your WordPress database**

**A second volume that contains your WordPress website files.**

### Network to implement
**A docker-network that establishes the connection between your containers.**

**Configure `seunan.42.fr` to point to your local IP address.**

### Things to study
**What is the difference between Alpine Linux and Debian?**

**How daemons work and whether it’s a good idea to use them or not?**

**PID 1 and the best practices for writing Dockerfiles.**

## Bonus part

### Set up redis cache for your WordPress website in order to properly manage the cache.

### Set up a FTP server container pointing to the volume of your WordPress website.

### Create a simple static website in the language of your choice except PHP (Yes, PHP is excluded!). For example, a showcase site or a site for presenting your resume.

### Set up Adminer.

### Set up a service of your choice that you think is useful.
