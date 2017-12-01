instalar java 8
$ sudo add-apt-repository ppa:webupd8team/java
$ sudo apt update; sudo apt install oracle-java8-installer
$ sudo apt install oracle-java8-set-default

listar versoes java
$ update-java-alternatives --list

setar como padrao
$ sudo update-java-alternatives --set /path/to/java/version

mostrar versao atual
$ java -version
$ javac -version
