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
// $ docker run --rm -it 89066d1f15e8 sh
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

$ docker commit <container_id> <dockerhub_id/repositorio>:<tag>
	'salva mudanças feitas num container como um novo repositório'

$ docker build <path>
// $ docker build -t gabrielmirandat/node_course_udemy --network network_name .
	'constroi uma imagem de um Dockerfile'

	FLAGS
	-t <dockerhub_id/repositorio>:<tag>
		'indica repositório para a imagem sendo construída'
	--no-cache=true
		'remove cacheamento que causa erro quando os RUN não estão encadeados'

$ docker tag <image_id> <new_repository_name>:<tag>
// $ docker tag 89066d1f15e8 gabrielmirandat/node_course_udemy:1.01
	'usado para renomear nome do repositorio util para mandar para o dockerhub'
	'para o dockerhub, precisa ser <dockerhub_id/repositorio>:<tag>'
	'nunca use latest!'
$ docker login
	'faz login no dockerhub'

	FLAGS
	--username=<usuario>
		'indica nome de usuario dockerhub'

$ docker push <dockerhub_id/repositorio>:<tag>
	'faz push para dockerhub'

# Outros comandos
$ exit 
	'sai do container e mata ele'

# Dockerfile
	FROM - imagem base
	RUN - comandos de instalação da imagem
	CMD - comandos a serem executados quando um container é iniciado
	COPY - copia arquivos ou diretórios do contexto build para o sistema de arquivos do container
	ADD - como um copy, mas pode baixar da internet e descomprimir arquivos automaticamente, copy é preferível
	USER - indica o usuario que sera usado nos containers
	WORDIR - seta o diretório de trabalho inicial

	- cada instrução cria uma camada de imagem na imagem gerada
	- sempre que instalar algo coloca -y para aceitar os prompts automaticamente
	- encadear RUN para reduzir número de layers criadas
	- instalar pacotes em ordem alfanumerica
	






