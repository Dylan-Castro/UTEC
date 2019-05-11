package com.company;
class MultithreadingDemo extends Thread
{
    public void run()
    {
        ChocolateBoiler chocolate = ChocolateBoiler.getInstance();
    }
}


public class Main {
    public static void main(String[] args) throws InterruptedException {
        for (int i=0; i<8; i++)
        {
            Thread object = new Thread(new MultithreadingDemo());
            object.start();
            object.join();
        }
    }
}
