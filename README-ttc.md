ttc-drupal
==========

A Drupal site for the Technology Transfer Center of the National Cancer Institute, part of the National Institutes of Health.

Dependencies
----------
* Linux, Unix, Windows, or Mac OS X
* [PHP 5.2.5+](https://secure.php.net/), installed and configured
* [Apache](https://httpd.apache.org/), installed and configured
* [MySQL 5.0.15+ or MySQL 5.1.30+](https://www.mysql.com/) or [MariaDB 5.1.44](https://mariadb.org/) or [Percona Server 5.1.70+](https://www.percona.com/software/mysql-database/percona-server) with the PDO extension for PHP (see "[What is PDO?](https://www.drupal.org/requirements/pdo)" on Drupal.org), installed and configured
* [drush](http://docs.drush.org/en/master/)

**Note:** for local development or testing only, it is possible to use [Acquia Dev Desktop](https://www.acquia.com/products-services/dev-desktop) instead, which comes with PHP, Apache, MySQL, and drush (and configures them for Drupal development).

### Additional dependencies for development
* [Node.js](https://nodejs.org/) -- using [nvm](https://github.com/creationix/nvm) (for Linux/OS X) or [NVM for Windows](https://github.com/coreybutler/nvm-windows) is recommended
* [Git](https://git-scm.com/)
* [grunt-cli](https://github.com/gruntjs/grunt-cli), a Node.js package (must be installed globally) -- once Node.js is installed, run:
	```console
	npm install -g grunt-cli
	```
* [bower](https://github.com/bower/bower), a Node.js package (must be installed globally) -- once both Node.js and Git are installed, run:
	```console
	npm install -g bower
	```

Installation
----------
1. Export (for deployment) or checkout (for development) this repository:
	```console
	svn export https://OLD_SVN/svn/ocplttc/trunk/drupal/
	```
2. If you are not using Acquia Dev Desktop:
	1. Build the site:
		```console
		drush make ttc.make
		```
	2. Install the site. **Change the `db-url` parameter to include your specific SQL database connection details.**
		```console
		drush site-install --db-url=mysql://username:password@localhost:port/ttc
		```
3. If you *are* using Acquia Dev Desktop:
	1. Download Drupal 7 from https://www.drupal.org/project/drupal and extract the archive to the directory where you exported or checked out the `ttc.make` file
	2. In Acquia Dev Desktop, import this directory as a new site. See the [Acquia Dev Desktop documentation](https://docs.acquia.com/dev-desktop2/start/local) if you're unsure how to do this.
		* For the "local site name", use "ttc".
	3. Build the site -- note the `no-core` flag, which prevents drush from trying to download Drupal on its own:
		```console
		drush make --no-core ttc.make
		```
	4. In a web browser, navigate to https://ttc.dd:8083 and run through the installation steps. The database steps will be completed automatically by Acquia Dev Desktop.
4. You're done! Now you can work with Drupal as usual.


Troubleshooting
----------
- If the system cannot find "node_module" paths in ttctheme, install the following patch: https://www.drupal.org/files/issues/ignore_front_end_vendor-2329453-111.patch. The related issue is at https://www.drupal.org/node/2329453


