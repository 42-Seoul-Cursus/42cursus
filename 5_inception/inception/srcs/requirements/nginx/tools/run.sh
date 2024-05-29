#!/bin/sh

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Cadet/CN=localhost"
exec nginx -g "daemon off;"
