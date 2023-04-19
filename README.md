# C++设计模式

## 什么是设计模式

> “每一个模式描述了一个在我们周围不断重复发生的问题，以及该问题的解决方案的核心。这样，你就能一次又一次地使用该方案而不必做重复劳动”。 ——Christopher Alexander

## 如何解决复杂性？

- 分解
  - 人们面对复杂性有一个常见的做法：分而治之，将大问题分解为多个小问题，将复杂问题分解为多个简单问题。
- 抽象
  - 更高层次来讲，人们处理复杂性有一个通用的技术，即抽象。由于不能掌握全部的复杂对象，我们选择忽视它的非本质细节，而去处理泛化和理想化了的对象模型。

## 面向对象设计原则

1. 依赖倒置原则（DIP）
   - 高层模块（稳定）不应该依赖于低层模块（变化），二者都应该依赖于抽象（稳定）。
   - 抽象（稳定）不应该依赖于实现细节（变化），实现细节应该依赖于抽象（稳定）。
2. 开放封闭原则（OCP）
   - 对扩展开放，对修改封闭。
   - 类模块应该是可拓展的，但是不可修改。
3. 单一职责原则（SRP）
   - 一个类应该仅有一个引起它变化的原因。
   - 变化的方向隐含着类的责任。
4. 里氏替换原则（LSP）
   - 子类必须能够替换它们的基类（IS-A）。
   - 继承表达类型抽象。
5. 接口隔离原则（ISP）
   - 不应该强迫客户程序依赖它们不用的方法。
   - 接口应该小而完备。
6. 优先使用对象组合，而不是类继承
   - 类继承通常为“白箱复用”，对象组合通常为“黑箱复用”。
   - 继承在某种程度上破坏了封装性，子类父类耦合度高。
   - 对象组合则只要求被组合的对象具有良好定义的接口，耦合度低。
7. 封装变化点
   - 使用封装来创建对象之间的分界层，让设计者可以在分界层的一侧进行修改，而不会对另一侧产生不良的影响，从而实现层次间的松耦合。
8. 针对接口编程，而不是针对实现编程
   - 不将变量类型声明为某个特定的具体类，而是声明为某个接口。
   - 客户程序无需获知对象的具体类型，只需要知道对象所具有的接口。
   - 减少系统中各部分的依赖关系，从而实现“高内聚、低耦合”的类型设计方案。

## 从封装变化角度对模式分类

### 组件协作

- :white_check_mark: Template Method（模板方法）
- :black_square_button: Observer / Event（观察者模式 / 事件模式）
- :white_check_mark: Strategy（策略模式）

### 单一职责

- :black_square_button: Decorator（装饰器模式）
- :black_square_button: Bridge（桥接模式）

### 对象创建

- :black_square_button: Factory Method（工厂方法）
- :black_square_button: Abstract Factory（抽象工厂）
- :black_square_button: Prototype（原型模式）
- :black_square_button: Builder（创建者模式）

### 对象性能

- :white_check_mark: Singleton（单例模式）

- :black_square_button: Flyweight（享元模式）

### 接口隔离

- :black_square_button: Facade（门面模式）
- :black_square_button: Proxy（代理模式）
- :black_square_button: Mediator（中介者模式）
- :black_square_button: Adapter（适配器模式）

### 状态变化

- :black_square_button: Memento（备忘录模式）
- :black_square_button: State（状态模式）

### 数据结构

- :black_square_button: Composite（组合模式）
- :black_square_button: Iterator（迭代器模式）
- :black_square_button: Chain of Responsibility（责任链模式）

### 行为变化

- :black_square_button: Command（命令模式）
- :black_square_button: Visitor（访问者模式）

### 领域问题

- :black_square_button: Interpreter（编译器模式）

## 总结

现代较少用的模式

- Builder
- Mediator
- Memento
- Iterator
- Chain of Responsibility
- Command
- Visitor
- Interpreter