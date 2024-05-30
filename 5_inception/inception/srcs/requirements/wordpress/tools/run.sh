#!/bin/sh

while [ ! -e /var/www/html/wp-config.php ]; do
    # https://make.wordpress.org/cli/handbook/guides/quick-start/
    /scripts/wp-cli.phar core config --dbname=${WORDPRESS_DB_NAME} --dbuser=${WORDPRESS_DB_USER} --dbpass=${WORDPRESS_DB_PASSWORD} --dbhost=${WORDPRESS_DB_HOST} --dbprefix=${WORDPRESS_TABLE_PREFIX} --path=/var/www/html --allow-root
done

/scripts/wp-cli.phar core install --url=${DOMAIN_NAME} --title=${WORDPRESS_TITLE} --admin_user=${WORDPRESS_ADMIN_ID} --admin_password=${WORDPRESS_ADMIN_PASSWORD} --admin_email=${WORDPRESS_ADMIN_EMAIL} --path=/var/www/html --allow-root
# https://developer.wordpress.org/cli/commands/option/
/scripts/wp-cli.phar option update siteurl ${DOMAIN_NAME} --path=/var/www/html --allow-root
/scripts/wp-cli.phar option update home ${DOMAIN_NAME} --path=/var/www/html --allow-root
# https://developer.wordpress.org/cli/commands/user/create/
/scripts/wp-cli.phar user create ${WORDPRESS_USER_ID} ${WORDPRESS_USER_EMAIL} --role=author --user_pass=${WORDPRESS_USER_PASSWORD} --path=/var/www/html --allow-root

# https://linux.die.net/man/8/php-fpm
exec "$@"
