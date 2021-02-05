# Design Patterns for Software Engineering

## 1) Strategy 

The Strategy pattern is used when a family of algorithms are available to perform the same task. Each algorithm is encapsulated and made interchangeable. This allow clients to use the algorithm implementation independently, favoring the OO principle of encapsulation what varies in a system. Normally, it is implemented using interfaces and compositions. 

A simple program that defines different Ducks and how each of them perform common actions, like fly and quack, is implemented.

## 2) Observer (IMPORTANT)

The Observer pattern is widely used when we have a one-to-many dependency between objects. When one object changes its state, all of the dependents are notified and updated automatically. A common usage of the Observer pattern is alongside listener methods, which trigger some event when some action is performed. 

A WeatherApp is constructed to demonstrate how this pattern works.

## 3) Decorator

The Decorator pattern attaches new functionalities to an object dynamically. This provides a flexible and elegant solution to subclassing. This pattern relies is an important OO principle, which considers that classes should be open for extension, but closed for modification.

A CoffeeShopApp is utilized to illustrate this pattern.

## 4) Factory (IMPORTANT)

The Factory pattern is a extremely important design pattern. Its main idea is to promote loose coupling by reducing the dependency of your application to concrete classes, because of that it is highly based on the usage of abstractions. Normally, it is implemented using interfaces that creates objects, but lets a class defer instantiation to the subclasses. The Factory pattern is also known to be divided in two types:

- Abstract Factory = relies on object composition with object creation being implemented in methods exposed in the factory interface.
- Factory Method = relies in inheritance with object creation being delegated to subclasses which implement the factory method to create objects.

A PizzaApp is implemented to show how this pattern can be useful.

## 5) Singleton

The Singleton design pattern ensures a class only has one instance and provide a global point of acess. Normally, this design is used when classes are within a multithreading environment, in order to avoid race conditions between objects. The main idea of the Singleton pattern is to make the constructor of the Singleton class private and acessible with a static class method, which is normally called getInstance(). This way each time the user wants a Singleton object it will receive its unique reference.

A CholateBoiler machine is implemented using this pattern.

## 6) Command (IMPORTANT)

The Command pattern decouples an object making requests from the objects that know how to perform the requests. A Command object is at the center of this decoupling and encapsulates a receiver with an action. An invoker makes a request to a Command object by calling the execute() method, which invokes the actions in the receiver. The main application of the pattern is in request queues when a set of actions must always follow a certain order and in undoing actions.

A RemoteControl which can control several devices in a smart-house is implemented to show the capabilities and advantages of this powerful pattern.


