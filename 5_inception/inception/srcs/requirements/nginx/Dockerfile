# https://stackoverflow.com/questions/49118579/alpine-dockerfile-advantages-of-no-cache-vs-rm-var-cache-apk
# https://wiki.alpinelinux.org/wiki/Alpine_Package_Keeper#Local_Cache
FROM alpine:3.19

RUN apk update && \
    apk add --no-cache \
        nginx \
        openssl && \
    mkdir -p \
        /etc/nginx/ssl \
        /var/www/html \
        /scripts

# Copy the configuration file
COPY conf/default.conf /etc/nginx/http.d/default.conf
COPY tools/run.sh /scripts/run.sh

RUN chmod -R 755 /scripts

# Port to expose, Just documentation(Not necessary)
EXPOSE 443/tcp

ENTRYPOINT ["/scripts/run.sh"]

CMD ["nginx", "-g", "daemon off;"]
