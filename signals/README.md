Three ways of generating signals in linux:
1. Raising a signal from OS to a process(ctrl+C)
2. Sending a signal from process A to itself(using raise())
3. Sending signal from process A to process B (using kill())
