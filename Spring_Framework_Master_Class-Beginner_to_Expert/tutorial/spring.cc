@Component
Define uma BEAN!
Spring sabe que tem que gerenciar estas classes com sua injeção de dependência
Ele gerencia as instancias das classes

@Autowired
Define uma DEPENDENCIA da BEAN!
Diz para o Spring qual é a dependencia que ele tem que gerenciar 
quando a classe é @Component

@SpringBootApplication
Diz ao Spring Boot para escanear o pacote e subpacotes em que esta classe está definida
Escanear é encontrar beans e dependencias

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
