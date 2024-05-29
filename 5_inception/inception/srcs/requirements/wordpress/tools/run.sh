#!/bin/sh
mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

sed -i "s/define( 'DB_NAME', 'database_name_here' );/define( 'DB_NAME', '${WORDPRESS_DB_NAME}' );/" /var/www/html/wp-config.php 
sed -i "s/define( 'DB_USER', 'username_here' );/define( 'DB_USER', '${WORDPRESS_DB_USER}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'DB_PASSWORD', 'password_here' );/define( 'DB_PASSWORD', '${WORDPRESS_DB_PASSWORD}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'DB_HOST', 'localhost' );/define( 'DB_HOST', '${WORDPRESS_DB_HOST}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'AUTH_KEY',         'put your unique phrase here' );/define( 'AUTH_KEY',         '${WORDPRESS_AUTH_KEY}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'SECURE_AUTH_KEY',  'put your unique phrase here' );/define( 'SECURE_AUTH_KEY',  '${WORDPRESS_SECURE_AUTH_KEY}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'LOGGED_IN_KEY',    'put your unique phrase here' );/define( 'LOGGED_IN_KEY',    '${WORDPRESS_LOGGED_IN_KEY}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'NONCE_KEY',        'put your unique phrase here' );/define( 'NONCE_KEY',        '${WORDPRESS_NONCE_KEY}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'AUTH_SALT',        'put your unique phrase here' );/define( 'AUTH_SALT',        '${WORDPRESS_AUTH_SALT}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'SECURE_AUTH_SALT', 'put your unique phrase here' );/define( 'SECURE_AUTH_SALT', '${WORDPRESS_SECURE_AUTH_SALT}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'LOGGED_IN_SALT',   'put your unique phrase here' );/define( 'LOGGED_IN_SALT',   '${WORDPRESS_LOGGED_IN_SALT}' );/" /var/www/html/wp-config.php
sed -i "s/define( 'NONCE_SALT',       'put your unique phrase here' );/define( 'NONCE_SALT',       '${WORDPRESS_NONCE_SALT}' );/" /var/www/html/wp-config.php
sed -i "s/\$table_prefix  = 'wp_';/\$table_prefix  = '${WORDPRESS_TABLE_PREFIX}';/" /var/www/html/wp-config.php

exec php-fpm82 -F
