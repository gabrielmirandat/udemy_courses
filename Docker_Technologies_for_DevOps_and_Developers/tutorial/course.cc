# Hypervisor providers
VMware, Virtual Box

# Cloud providers that store VMs
AWS, Microsoft Azure

# Container VM
Apenas um OS
Bem mais leve que VMs
Um PC pode ter vários containers

# Arquitetura
Docker client
	- aceita comandos do usuário
Docker daemon 
	- realiza os comandos 
	- precisa rodar em linux
	- roda no sistema (se linux) ou numa VM (windows, osx)
Registry
	- armazena

# Principal
Images
	- templates para criar containers
	- criadas com 'docker build'

Containers
	- sistema virtual a partir das imagens

Registry
	- servidor de imagens públicas (docker hub) ou privadas

Repository
	- armazena várias versões da imagem com tags

# Comandos
$ docker info 
	'informações do sistema'
$ docker images 
	'mostra as imagens locais'
$ docker run <imagem>:<tag> <comando> <argumento>
	'roda um container, se a imagem não existir tenta baixar do dockerhub'
	
	COMANDO/ARGUMENTO 
	echo "hello world"
		'printa na tela'
	ls /
		'mostra pasta root'
	
	FLAGS
	-it 
		'inicia modo interativo do container com stdin e stdout'
	-d 
		'roda container em background'
	-p 8888:8080
		'expoe a porta 8080 do container para a porta 8888 do host'
	--rm
		'mata o container sempre que sair dele'
	--name hello_world
		'especifica um nome para o container sendo rodado'

$ docker ps 
	'mostra os containers ativos'

	FLAGS
	-a 
		'mostra ativos e inativos'

$ docker inspect <container_id>
	'da informacoes sobre o container'

$ docker logs <container_id>
	'mostra os logs de um container rodado em background'

$ docker history <imagem>:<tag>
	'mostra as camadas da imagem'

# Outros comandos
$ exit 
	'sai do container e mata ele'






