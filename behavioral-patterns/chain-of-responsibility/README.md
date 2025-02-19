## chain-of-responsibility

责任链模式是一种行为设计模式，它允许多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合。这些对象被连接成一条链，请求沿着这条链传递，直到有对象处理它为止。

### 使用场景

1. **多个对象可以处理相同请求**：
    - 例如多个日志处理器分别处理不同级别的日志。
2. **动态指定请求的处理顺序**：
    - 可以通过动态构建责任链来调整请求的处理流程。
3. **希望将请求的发送者与接收者解耦**：
    - 客户端只需将请求发送到责任链的入口，无需关心具体的处理者。
