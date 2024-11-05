SequenceDetectorMarks: 30
Problem Description
Nitya is a digital circuit designer. She decides to design a sequence detector which may be either an overlapping model or a non-overlapping model.

Sequence detector is a digital circuit which is used to detect the sequences from a series of numbers. These detectors may be overlapping or non-overlapping.

Example of how non-overlapping sequence detector detects sequence 101 is depicted below.

![alt text](image.png)

So, from the series given above, say Series 1, non-overlapping sequence detector detects four 101 sequences

Example of how overlapping sequence detector detects sequence 101 is depicted below

![alt text](image-1.png)

From the series given above, say Series 2, overlapping sequence detector detects three 101 sequences. The last 5 digits in the given series i.e., 10101 has two 101 sequences where the middle 1 is used by both left and right trailing digits.

The process of any circuit design starts with requirements and state transition diagram to represent that requirement. So, Nitya asked her assistant to create different state transition diagrams for the hardware needed to detect different sequences. Hardware will need to be customized per sequence. The assistant designed different hardware for different sequences, but forgot to mention the sequence to be detected on respective state transition diagrams. So now, Nitya must go through every sequence and determine, what is the sequence to be detected and whether the sequence detector is overlapping or non-overlapping.

So, she decides to code the state transition diagram and find which sequence is to be detected and what is the type of detector.

state transition diagram example and explanation:

![alt text](image-2.png)

Here a and b represent different states in the state transition diagram. State of circuit changes from one state to another depending on inputs provided by arrow representations. Here, initial state starts with 'a' and then goes to 'b' and then back to 'a'. A sequence can be formed only when state changes.

For example,
![alt text](image-3.png)

Here state changes from a to b when input is 1 and giving output 0. So, the sequence starts with 1. State changes from b to c when input is 0. So, the second digit in sequence is 0. State changes from c to a when input is 1 and giving output as 1, and also when input is 0 and giving output as 0. But the output is 1 only when input is 1 from the above diagram. So, the third digit in sequence is 1. Thus, the sequence that this state transition diagram can detect is 101.

A sequence detector is non-overlapping when state changes from final state to initial state with output being 1. In this case, initial state is a and final state is c. In any other case, it is an overlapping sequence detector. A sequence is said to detected by observing the output when the output goes to 1. So, the above state model is non-overlapping sequence detector.

Constraints
2 <= Length of sequence <= 10

Each input line contains 4 space separated inputs viz. < present_state (char), next_state (char), input (0/1), output (0/1)>

4 < = Number of lines of input < = 20

For a sequence to be detected, every state must be visited at least once and the number of transitions should be equal to Number of states

A given state transition diagram always corresponds to one sequence. As explained in Input section, the number of chars will depict the number of states in a state transition diagram

Input
Input consists of variable number of lines of input where each line contains 4 space separated inputs which represents present_state (char), next_state (char), input (0/1), output (0/1) of the state transition diagram.

Output
Print the sequence to be detected in first line.

Print the type of sequence detector in the second line. If the detector is non-overlapping print "Non Overlapping Sequence Detector" else print "Overlapping Sequence Detector".

Time Limit (secs)
1

Examples
Input

a b 1 0

b c 0 0

b b 1 0

a a 0 0

c a 0 0

c a 1 1

Output

101

Non Overlapping Sequence Detector

Explanation

Here a and b represent different states in state transition diagram. state of circuit changes from one state to another depending on inputs provided by arrow representation. Initial state starts with 'a' and then goes to 'b' and then to 'c' and so on. A sequence can be formed only when state changes.

![alt text](image-4.png)

Here state changes from a to b when input is 1 and output is 0. So, the sequence starts with 1. State changes from b to c when input is 0. So, the second digit in sequence is 0. State changes from c to a when input is 1 and output is 1, and also when input is 0 and output is 0. But the output is 1 only when input is 1 from the above diagram. So, the third digit in sequence is 1. Thus, the sequence that this state model diagram can detect is 101

Since a sequence detector is non-overlapping when state changes from final state to initial state with output being 1, the state transition diagram above is a non-overlapping sequence detector, where, the initial state is a and final state is c.

Thus, the output is

101

Non Overlapping Sequence Detector

Example 2

Input

a b 1 0

a a 0 0

b a 0 0

b c 1 0

c c 1 0

d a 0 0

d b 1 1

c d 0 0

Output

1101

Overlapping Sequence Detector

Explanation

The diagram for given inputs is:

![alt text](image-5.png)

Using above state transition diagram, the sequence is 1101 and detector is overlapping detector. Thus, the output is

1101

Overlapping Sequence Detector