# https://github.com/docker-library/wordpress/blob/2eba26f088c12dea179623ee8af5cb52e6f60c4a/latest/php8.1/fpm-alpine/Dockerfile
# https://wiki.alpinelinux.org/wiki/WordPress
# https://docs.rockylinux.org/guides/web/php/
# https://www.php.net/manual/en/mysqli.overview.php
# https://dev.mysql.com/downloads/connector/php-mysqlnd/
# https://inpa.tistory.com/entry/PHP-%F0%9F%93%9A-DB-%EB%8B%A4%EB%A3%A8%EA%B8%B0-mysqli-%EB%B0%A9%EC%8B%9D
FROM alpine:3.19

RUN apk update && \
    apk add --no-cache \
        wget \
        php-fpm \
        php-mysqli php82-cli php82-phar php82-mbstring php82-xml php82-mysqli php82-json php82-curl && \
    wget https://wordpress.org/wordpress-6.5.3.tar.gz -O /tmp/wordpress.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /tmp && \
    mkdir -p \
        /var/www/html \
        /scripts && \
    mv /tmp/wordpress/* /var/www/html/ && \
    rm -rf /tmp/* && \
    touch \
        /var/log/php82/www.error.log \
        /var/log/php82/www.access.log

COPY conf/www.conf /etc/php82/php-fpm.d/www.conf
COPY tools/run.sh /scripts/run.sh

RUN chmod 7555 /scripts/run.sh

EXPOSE 9000

VOLUME /var/www/html

CMD ["/scripts/run.sh"]
