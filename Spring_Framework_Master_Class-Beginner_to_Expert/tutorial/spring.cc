Ideia geral
-> Para achar um BEAN
	Faz um 'component scan' no pacote para encontrar todos os beans (@Component)
-> Pra casar AUTOWIRED
	Se só tem um @Component do tipo do construtor, ele serve como dependencia escolhida
	Se tem mais de um, @Primary escolhe qual deve ser escolhido primeiro como dependencia injetada

Projetos
- Spring Boot: microserviços
- Spring Cloud: tornar o serviço cloudable
- Spring Data: facilita integração com banco de dados
- Spring Integration: facilita integração de acordo com padrões


@Component
Define uma BEAN!
Spring sabe que tem que gerenciar estas classes com sua injeção de dependência
Ele gerencia as instancias das classes

@Autowired
Define uma DEPENDENCIA da BEAN!
Diz para o Spring qual é a dependencia que ele tem que gerenciar
quando a classe é @Component
Pode ser via CONSTRUTOR, SETTER, OU NENHUM!! 'o nenhum serve como SETTER'

@SpringBootApplication
Diz ao Spring Boot para escanear o pacote e subpacotes em que esta classe está definida
Escanear é encontrar beans e dependencias

@Primary
Diz ordem para escolha numa injeção de dependência @Autowired

Beans
É um objeto de uma classe
São as diferentes instancias de @Components que o Spring gerencia
O Spring gerencia beans e suas dependencias

Inversion of Control
A classe que antes criaria a instancia da dependencia
Agora quem cria essa instancia é o Spring

IOC container
Container da inversao de controle

Application Context
É o IOC container do Spring
Gerencia todos os BEANS e suas DEPENDENCIAS

ApplicationContext applicationContext =
	SpringApplication.run(SpringIn5StepsApplication.class, args);
BinarySearchImpl binarySearch =
	applicationContext.getBean(BinarySearchImpl.class)

Loosely coupled
Escolher dinamicamente entre uma implementação e outra
Por meio de interfaces!
Ou por meio do SPRING!

Spring Boot Starter
Gerencia todas as dependencias do MAVEN

Spring
QUais são as beans?
Quais são as dependencias de uma bean?
Onde procurar por beans?
