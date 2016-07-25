#include "stack.h"

EmptyQueueException::EmptyQueueException(string message) {
  msg = message;
}

string EmptyQueueException::getMessage() {
  return msg;
}

DivideByZero::DivideByZero(string message) {
  msg = message;
}

string DivideByZero::getMessage() {
  return msg;
}

NotAnInteger::NotAnInteger(string message) {
  msg = message;
}

string NotAnInteger::getMessage() {
  return msg;
}
