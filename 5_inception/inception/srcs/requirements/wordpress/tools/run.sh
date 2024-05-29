#!/bin/sh

# https://make.wordpress.org/cli/handbook/guides/installing/
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

if [ ! -f /var/www/html/wp-config.php ]; then
    # https://make.wordpress.org/cli/handbook/guides/quick-start/
    wp core config --path=/var/www/html --dbname=${WORDPRESS_DB_NAME} --dbuser=${WORDPRESS_DB_USER} --dbpass=${WORDPRESS_DB_PASSWORD} --dbhost=${WORDPRESS_DB_HOST} --dbprefix=${WORDPRESS_TABLE_PREFIX} --allow-root
    wp core install --url=${DOMAIN_NAME} --title=${WORDPRESS_TITLE} --admin_user=${WORDPRESS_ADMIN_USER} --admin_password=${WORDPRESS_ADMIN_PASSWORD} --admin_email=${WORDPRESS_ADMIN_EMAIL} --allow-root
    # https://developer.wordpress.org/cli/commands/option/
    wp option update siteurl ${DOMAIN_NAME} --path=/var/www/html --allow-root
    wp option update home ${DOMAIN_NAME} --path=/var/www/html --allow-root
    # https://developer.wordpress.org/cli/commands/user/create/
    wp user create ${WORDPRESS_USER} ${WORDPRESS_USER_EMAIL} --role=author --user_pass=${WORDPRESS_USER_PASSWORD} --path=/var/www/html --allow-root
fi

exec php-fpm82 -F
