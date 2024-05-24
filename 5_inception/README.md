# inception

- [inception](#inception)
  - [Mendatory part](#mendatory-part)
    - [Container to implement](#container-to-implement)
      - [A Docker container that contains NGINX with TLSv1.2 or TLSv1.3 only](#a-docker-container-that-contains-nginx-with-tlsv12-or-tlsv13-only)
      - [A Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx.](#a-docker-container-that-contains-wordpress--php-fpm-it-must-be-installed-and-configured-only-without-nginx)
      - [A Docker container that contains MariaDB only without nginx.](#a-docker-container-that-contains-mariadb-only-without-nginx)
    - [Volumes to implement](#volumes-to-implement)
    - [Network to implement](#network-to-implement)
    - [Set up a Alpine Linux on virtualbox](#set-up-a-alpine-linux-on-virtualbox)
    - [Things to study](#things-to-study)
  - [Bonus part](#bonus-part)
    - [Set up redis cache for your WordPress website in order to properly manage the cache.](#set-up-redis-cache-for-your-wordpress-website-in-order-to-properly-manage-the-cache)
    - [Set up a FTP server container pointing to the volume of your WordPress website.](#set-up-a-ftp-server-container-pointing-to-the-volume-of-your-wordpress-website)
    - [Create a simple static website in the language of your choice except PHP (Yes, PHP is excluded!). For example, a showcase site or a site for presenting your resume.](#create-a-simple-static-website-in-the-language-of-your-choice-except-php-yes-php-is-excluded-for-example-a-showcase-site-or-a-site-for-presenting-your-resume)
    - [Set up Adminer.](#set-up-adminer)
    - [Set up a service of your choice that you think is useful.](#set-up-a-service-of-your-choice-that-you-think-is-useful)


## Mendatory part

[**Container to implement:**](#container-to-implement)
- [x] A Docker container that contains NGINX with TLSv1.2 or TLSv1.3 only
  - [x] NGINX container must be the only entrypoint into your infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3 protocol.
- [x] A Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx.
- [x] A Docker container that contains MariaDB only without nginx.

[**Volumes to implement:**](#volumes-to-implement)
- [x] A volume that contains your WordPress database
- [x] A second volume that contains your WordPress website files.

[**Network to implement:**](#network-to-implement)
- [x] A docker-network that establishes the connection between your containers.

[**Things to study:**](#things-to-study)
- [x] [What is docker?](https://github.com/seungwonme/DevOps/tree/main/docker)
- [x] [Alpine Linux vs Debian](https://stackshare.io/stackups/alpine-linux-vs-debian)
- [x] how daemons work and whether it’s a good idea to use them or not?
- [x] PID 1 and the best practices for writing Dockerfiles.

### Container to implement

구현에 대한 설명은 [DevOps](https://github.com/seungwonme/DevOps/tree/main/docker) 저장소와 파일마다 주석 처리해놓은 링크를 참고하면 된다.

#### A Docker container that contains NGINX with TLSv1.2 or TLSv1.3 only
> NGINX container must be the only entrypoint into your infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3 protocol.

**NGINX**\
Nginx란 웹서버, 프록시 서버 프로그램이다.

- [Nginx란 무엇인가? : 네이버 블로그](https://blog.naver.com/gi_balja/223028077537)
- [Nginx란 무엇인가?](https://dkswnkk.tistory.com/513)

**TLS**\
TLS(Transport Layer Security)는 네트워크 통신을 보호하기 위한 암호화 프로토콜이다. SSL(Secure Sockets Layer)의 후속 버전이다.\
HTTPS는 HTTP의 보안 버전으로, HTTP 통신을 암호화하기 위해 TLS를 사용한다.

- [TLS의 정의 및 이해와 TLS1.2과 TLS1.3의 차이](https://sym312.tistory.com/14)
- [TLS 1.3 특징, 기존 TLS 버전과의 차이점](https://blog.naver.com/PostView.nhn?blogId=cr0sscert&logNo=221706613801)
- [[HTTPS] SSL/TLS 보안 프로토콜 이해하기( TLS 1.2 / TLS 1.3 )](https://aday7.tistory.com/entry/HTTPS-SSLTLS-%EB%B3%B4%EC%95%88-%ED%94%84%EB%A1%9C%ED%86%A0%EC%BD%9C-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-TLS-12-TLS-13)
- [SSL/TLS의 이해와 TLS 1.3으로 업그레이드해야 하는 이유 - ITWorld Korea](https://www.itworld.co.kr/news/113007)

#### A Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx.

**WordPress**\
워드프레스는 PHP와 MySQL을 사용하는 오픈 소스 콘텐츠 관리 시스템(CMS)이다.

- [Wordpress](https://en.wikipedia.org/wiki/WordPress)

**PHP-FPM**\
PHP란 웹 개발에 초점이 맞춰진 스크립트 언어이다.\
PHP란 일반적으로 모듈, 데몬, CGI 실팽 파일로 구성된 PHP 인터프리터로 실행된다.\
PHP-FPM은 PHP FastCGI Process Manager의 약자로, PHP FastCGI를 관리하는 프로세스 매니저이다.

- [PHP](https://en.wikipedia.org/wiki/PHP)

#### A Docker container that contains MariaDB only without nginx.

**MariaDB**\
MariaDB는 MySQL의 fork로, MySQL과 호환되는 오픈 소스 관계형 데이터베이스 관리 시스템(RDBMS)이다.

- [MariaDB](https://en.wikipedia.org/wiki/MariaDB)

### Volumes to implement
> Your volumes will be available in the /home/login/data folder of the host machine using Docker.

컨테이너 상에서 볼륨을 영구적으로 사용할 수 있는 방법은 세가지가 있다.

1. 호스트 볼륨을 이용하는 방법: 호스트 볼륨을 이용한다는 것은 호스트 운영체제의 디렉토리를 컨테이너 내에 마운트 시키는 작업을 말하며 가장 간단하고 직관적인 방법이다.
2. 볼륨 컨테이너를 이용하는 방법: 볼륨 컨테이너를 이용하는 방법은 볼륨을 특정 어플리케이션 컨테이너에서 마운트를 시키는것이 아니라, 볼륨 컨테이너(위 그림에서 Data-only Container)에서 볼륨 마운트만 진행을 하고 아무것도 하지 않는 컨테이너를 만들어서 어플리케이션 컨테이너가 볼륨 컨테이너를 참조하게 해서 마치 볼륨 컨테이너같이 사용하는 방법이다.
3. 도커 볼륨을 이용하는 방법: 호스트 볼륨과의 차이점은 호스트에 마운트할 경로를 지정했어야 했지만 도커 볼륨은 도커가 제공하는 볼륨 관리 기능을 통해서 볼륨을 생성하고 삭제하고 관리를 할 수 있다.

- [Docker Volumes](https://docs.docker.com/storage/volumes/)
- [도커 볼륨 다루기](https://seosh817.tistory.com/374)

**A volume that contains your WordPress database, A second volume that contains your WordPress website files.**\
docker compose를 사용하여 볼륨을 생성하고, wordpress와 mariadb 컨테이너에 볼륨을 마운트한다.

### Network to implement

사용자 정의된 사용자 정의 네트워크를 생성하고 여러 컨테이너를 동일한 네트워크에 연결할 수 있다.\
사용자 정의 네트워크에 연결되면 컨테이너는 컨테이너 IP 주소 또는 컨테이너 이름을 사용하여 서로 통신할 수 있습니다.

- [Docker Network](https://docs.docker.com/network/)
- [도커 네트워크 이해하기](https://seosh817.tistory.com/373?category=1035901)

**A docker-network that establishes the connection between your containers.**\
컨테이너간의 통신을 위해 사용자 정의 네트워크를 bridge 모드로 생성하고, wordpress와 mariadb 컨테이너를 생성할 때 해당 네트워크에 연결한다.

**Configure `seunan.42.fr` to point to your local IP address.**\
DNS 질의 순서는 다음과 같다.
1. 로컬 캐시, hosts 파일, 또는 브라우저 캐시에서 IP 주소를 찾는다.
2. 기본 DNS 서버에 질의한다.

hosts 파일을 수정하여 도메인 주소를 로컬 IP 주소로 매핑하면, 도메인을 구매하지 않고도 로컬에서 도메인 주소로 테스트할 수 있다.

- [DNS 프로세스 순서](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2008-r2-and-2008/dd197552(v=ws.10))
- [로컬에서 도메인 주소로 테스트하기 - hosts 파일](https://velog.io/@wooojini/%EB%A1%9C%EC%BB%AC%EC%97%90%EC%84%9C-%EB%8F%84%EB%A9%94%EC%9D%B8-%EC%A3%BC%EC%86%8C%EB%A1%9C-%ED%85%8C%EC%8A%A4%ED%8A%B8%ED%95%98%EA%B8%B0-hosts-%ED%8C%8C%EC%9D%BC)
- [[Windows] hosts 변경하기 :: Free Will](https://ldne.tistory.com/240)

### Set up a Alpine Linux on virtualbox

- [Alpine Linux](https://wiki.alpinelinux.org/wiki/Installing_Alpine_in_a_virtual_machine#VirtualBox)
  - [setup blog](https://linuxiac.com/how-to-install-alpine-linux/)
  - [gui blog](https://www.linkedin.com/pulse/adding-gui-graphical-user-interface-our-alpine-linux-virtual-ionica/)
  - [gui youtube](https://www.youtube.com/watch?v=LRx8QIzxsUQ)
- [virtualbox shared folder](https://blog.naver.com/zeroing2/221169283910)
- [virtualbox shared folder on alpine](https://wiki.alpinelinux.org/wiki/VirtualBox_shared_folders)
- [install docker on alpine](https://wiki.alpinelinux.org/wiki/Docker)
  - [install docker-compose on alpine](https://geekscircuit.com/install-docker-docker-compose-on-alpine-linux/)
- [how to install make on alpine](https://stackoverflow.com/questions/55190714/unable-to-use-make-in-alpine-image)
- [how to paste text from clipboard to vim](https://stackoverflow.com/questions/11489428/how-can-i-make-vim-paste-from-and-copy-to-the-systems-clipboard)

### Things to study
**What is the difference between Alpine Linux and Debian?**
- Alpine Linux: 가볍고 보안이 강화된 리눅스 배포판, 마이크로서비스와 컨테이너 환경에 적합
- Debian Linux: 안정적이고 다양한 패키지를 제공하는 리눅스 배포판, 서버 환경에 적합

**How daemons work and whether it’s a good idea to use them or not?**
Daemon은 리눅스 시스템이 부팅될 때 자동으로 실행되는 백그라운드 프로세스이다.\
사용자의 요청을 기다리고 있다가 요청이 발생하면 이에 적절히 대응하는 리스너와 같은 역할을 한다.\

리눅스에서 데몬을 실행하는 방법은 크게 두 가지가 있다.
- 혼자 스스로 동작하는 독자형(standalone)방식
- 데몬을 관리하는 슈퍼 데몬(super daemon)에 의해 동작하는 방식(xinetd)

보통 리눅스에서는 pid 1이 init 또는 systemd로 설정되어 있으며, 이는 시스템의 부팅 및 종료, 서비스 관리 등을 담당한다.\
마이크로 서비스에서는 슈퍼 데몬보다는 독자형 방식을 사용함으로써 서비스의 독립성을 높이고, 서비스의 확장성을 높일 수 있다.

- [Daemon](http://wiki.hash.kr/index.php/%EB%8D%B0%EB%AA%AC#init_.EB.8D.B0.EB.AA.AC)

**PID 1 and the best practices for writing Dockerfiles.**
- [best practices for writing Dockerfiles](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)
- [PID 1](https://medium.com/@boutnaru/the-linux-process-journey-pid-1-init-60765a069f17)
- [컨테이너 빌드에 대한 권장사항](https://cloud.google.com/architecture/best-practices-for-building-containers?hl=ko#signal-handling)
- [init system for Docker containers](https://engineeringblog.yelp.com/2016/01/dumb-init-an-init-for-docker.html)

## Bonus part

### Set up redis cache for your WordPress website in order to properly manage the cache.

### Set up a FTP server container pointing to the volume of your WordPress website.

### Create a simple static website in the language of your choice except PHP (Yes, PHP is excluded!). For example, a showcase site or a site for presenting your resume.

### Set up Adminer.

### Set up a service of your choice that you think is useful.
