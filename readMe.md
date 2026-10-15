# Random Generator
    This project is a simple application to help me learn more about C++
    The idea is simple
    build a generator class, consumer class, and analyzer class
    each running on a separate thread
    the producer writes into a shared buffer at a user specified rate (60Hz, 30Hz...)
    while the consumer keeps reading data whenever possible to a private buffer
    then the analyzer reads that data, and performs any desired operation.
