@Component
Spring sabe que tem que gerenciar estas classes com sua injeção de dependência
Ele gerencia as instancias das classes

@Autowired
Diz para o Spring qual é a dependencia que ele tem que gerenciar 
quando a classe é @Component

Beans
São as diferentes instancias de @Components que o Spring gerencia

Inversion of Control
A classe que antes criaria a instancia da dependencia
Agora quem cria essa instancia é o Spring

IOC container
Container da inversao de controle

Application Context
É o IOC container do Spring
Gerencia todos os beans e suas dependencias