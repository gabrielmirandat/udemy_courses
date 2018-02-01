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

# Integração contínua
circleci (VS JENKINS, TRAVIS)
	- servidor free de integração contínua
	- pode ser conectado diretamente com github

digitalocean (VS HEROKU)
	- oferece cloud para rodar máquinas virtuais e o que quiser

docker-swarm (VS KUBERNETES)
	- quando aplicação precisa ser escalada
	- muitos containers
	- um docker-swarm pode gerenciar multiplos hosts
	- 'manager node' manda tasks para os 'worker nodes'
|
|
|
|
|
|
|
|
|
|
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

Networks
	- tipos de rede
		- Closed / None (fechada)
			- isolada do mundo externo
			- não consegue pingar nada
			- máxima proteção contra mundo externo

		- Bridge
			- default
			- obtem uma quantidade de ips de rede
			- containers de uma mesma bridge conseguem se comunicar entre si
			- containers de bridges diferentes não se comunicam por default

		- Host
			- o container tem a mesma rede do pc
			- menor proteção contra mundo externo
			- acesso total a interface do computador

		- Overlay
			- permite deploy container em várias máquinas
			- necessita rodar docker engine em modo 'swarm'
			- geralmente usado em produção
|
|
|
|
|
|
|
|
|
|
# Comandos
$ docker info
	'informações do sistema'

$ docker images
	'mostra as imagens locais'

$ docker run <imagem>:<tag> <comando> <argumento>
// $ docker run --rm -it 89066d1f15e8 sh
// $ docker run -d -p 5000:5000 --network network_name 5ee7219a63eb
// $ docker run -d -p 5000:5000 --network network_name --link redis dockerapp:v0.3
// $ docker run -d --name container_3 --net my_bridge_network busybox sleep 1000
// $ docker run -d --name container_4 --net host busybox sleep 1000
	'roda um container, se a imagem não existir tenta baixar do dockerhub'

	COMANDO/ARGUMENTO
	echo "hello world"
		'printa na tela'
	ls /
		'mostra pasta root'
	bash
		'terminal'

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
	--link <nome>
		'cria um link entre o container sendo rodado e outro que se chama nome'
	--net <nome_rede>
		'define rede usada no container'

$ docker ps
	'mostra os containers ativos'

	FLAGS
	-a
		'mostra ativos e inativos'

$ docker inspect <container_id>
// $ docker inspect bb076b5a624b | grep IP
	'da informacoes sobre o container'

$ docker logs <container_id>
	'mostra os logs de um container rodado em background'

$ docker history <imagem>:<tag>
	'mostra as camadas da imagem'

$ docker commit <container_id> <dockerhub_id/repositorio>:<tag>
	'salva mudanças feitas num container como um novo repositório'

$ docker build <path>
// $ docker build -t gabrielmirandat/node_course_udemy --network network_name .
// $ docker build -t dockerapp:v0.2 --network network_name .
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
	-u <usuario>
		'indica nome de usuario dockerhub'
	-e <mail>
		'indica email'
	-p <senha>
		'indica a senha'

$ docker push <dockerhub_id/repositorio>:<tag>
	'faz push para dockerhub'

$ docker exec <container_id> <comando> <argumento>
// $ docker exec -it 01c4884ffbe0 bash
// $ docker exec -it container_1 ifconfig
	'para rodar um comando num container ativo'

	FLAGS
	-it
		'para rodar no modo iterativo'

	COMANDO/ARGUMENTO
		'vide docker run'

$ docker stop <container_name>
	'para container'

$ docker network ls
	'mostra os tipos de redes existentes na máquina'

$ docker network inspect <rede>
	'inspeciona rede'

$ docker network create --driver <tipo_rede> <nome_rede>
// $ docker network create --driver bridge my_bridge_network
	'cria uma nova rede'

$ docker network connect <nome_rede> <nome_container>
// $ docker network connect bridge container_3
	'adiciona conexão de uma rede ao container'

$ docker network disconnect <nome_rede> <nome_container>
// $ docker network disconnect bridge container_3
	'remove conexão de uma rede ao container'

# Outros comandos
$ exit
	'sai do container e mata ele'
|
|
|
|
|
|
|
|
|
|
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
|
|
|
|
|
|
|
|
|
|
# Docker-compose
	- Facilita a gerência de containers com script

$ docker-compose version
	'ver versão'

$ docker-compose up
	'build nos containers do docker-container'

	FLAGS
	-d
		'rodar em background'

$ docker-compose down
	'remove todos os containers do compose e a rede criada'

$ docker-compose ps
	'olha status dos containers rodados com compose'


$ docker-compose logs <comando>
	'olha logs'

	COMANDO/ARGUMENTO
	nome_container
		'mostra o log de um container específico'

$ docker-compose stop
	'para todos os containers sem removê-los'

$ docker-compose rm
	'remove todos os containers do compose'

$ docker-compose build
	'força que o compose de build na imagem'

$ docker-compose run <servico_compose> <comando> <argumentos>
// $ docker-compose run dockerapp python test.py
	'roda um comando em um serviço do docker-compose'
	'sobrescreve comando inicial'
|
|
|
|
|
|
|
|
|
|
# Docker-machine
	- Gerencia máquinas virtuais usadas para deploy

$ docker-machine ls
	'lista máquinas virtuais gerenciaveis'

$ docker-machine create --driver <driver> --digitalocean-access-token <token> <vm_name>
// $ docker-machine create --driver digitalocean --digitalocean-access-token 67c583fdd7a686d9c08a7619ff0755710c427b83284b250268fceb831347d012 docker-app-machine
	'solicita uma nova vm do digitalocean chamada docker-app-machine,
	 instala docker-engine na vm, gera certificados'

	FLAGS
	--driver <driver>
		'especifica driver da vm, podendo ser digitalocean, heroku'

	--digitalocean-access-token <token>
		'informa token da vm digitalocean a ser utilizada'


$ docker-machine env <vm_name>
$ eval $(<vm_name> env <vm_name>)
// $ docker-machine env docker-app-machine
// $ eval $(docker-machine env docker-app-machine)
	'configura o ambiente para o cliente docker'

$ docker-machine ssh <vm_name>
//$ docker-machine ssh swarm_node
	'entra dentro da máquina virtual'

//** $ docker-compose -f docker-compose-production up -d
	'deploy todos os serviços na vm definidos no .yml'
|
|
|
|
|
|
|
|
|
|
# Docker swarm
	- Gerencia deploy com muitos containers

//** $ docker-machine create --driver digitalocean --digitalocean-access-token 67c583fdd7a686d9c08a7619ff0755710c427b83284b250268fceb831347d012 swarm-manager
	'solicita uma nova vm do digitalocean chamada swarm-manager'

//** $ docker-machine env swarm-manager
//** $ eval $(docker-machine env swarm-manager)
	'configura o ambiente para o cliente docker'

//** $ docker-machine create --driver digitalocean --digitalocean-access-token 67c583fdd7a686d9c08a7619ff0755710c427b83284b250268fceb831347d012 swarm-node
	'solicita uma nova vm do digitalocean chamada swarm-node'

$ docker swarm init --advertise-addr <public_IP_swarm_node>
// $ docker swarm init --advertise-addr 104.131.81.40
	'inicia o swarm com um swarm node'

	FLAGS
	--advertise-addr <public_IP_swarm_node>
		'IP do nó swarm'

//** $ docker-machine ssh swarm_node
$ docker swarm join --token <token> <public_IP_swarm_node>
// $ docker swarm join --token SWMTKM-1-118* 104.131.81.40:2377
	'adiciona a vm atual como worker node na rede da vm swarm'

$ docker swarm leave
	'tira vm atual do swarm'
