#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
  int data;
  int minVal; // Текущий минимум в подстеке, начиная с этого узла
  Node *next;

  Node(int val, int minVal, Node *nextNode) : data(val), minVal(minVal), next(nextNode) {}
};

class MinStack
{
private:
  Node *topNode;

public:
  MinStack() : topNode(nullptr) {}

  void push(int value)
  {
    if (topNode == nullptr)
    {
      topNode = new Node(value, value, nullptr);
    }
    else
    {
      int newMin = min(value, topNode->minVal);
      topNode = new Node(value, newMin, topNode);
    }
  }

  void pop()
  {
    if (topNode != nullptr)
    {
      Node *temp = topNode;
      topNode = topNode->next;
      delete temp;
    }
  }

  int top()
  {
    if (topNode != nullptr)
    {
      return topNode->data;
    }
    else
    {
      cerr << "Stack is empty" << endl;
      return INT_MIN; // Возвращаем минимальное значение для инта в случае пустого стека
    }
  }

  int getMin()
  {
    if (topNode != nullptr)
    {
      return topNode->minVal;
    }
    else
    {
      cerr << "Stack is empty" << endl;
      return INT_MIN; // Возвращаем минимальное значение для инта в случае пустого стека
    }
  }
};

int main()
{
  MinStack stack;

  // Пример использования
  stack.push(3);
  stack.push(5);
  stack.push(2);
  cout << stack.getMin() << endl; // Выводит текущий минимум (2)
  stack.pop();
  cout << stack.top() << endl;    // Выводит верхний элемент (5)
  cout << stack.getMin() << endl; // Выводит текущий минимум (3)

  return 0;
}