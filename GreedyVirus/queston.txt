GreedyVirusMarks: 200
Problem Description
Phew, thank goodness you're back! During your absence, we observed some unauthorized data communication occurring from our storage warehouse. We promptly reported this to the chief since some data had already been stolen. The chief instructed us to trace the destination of the data theft. Our storage warehouse comprises individual data containers, arranged in an M*N matrix, with each container holding varying quantities of data represented as units. The containers are organized in M rows and N columns (with indexing starting from 1).

Our observation revealed that the virus consistently targets the container with the maximum data units. However, when two containers have equal data units, the virus's behavior becomes unclear, and we must avoid such scenarios. To determine the data's destination, continuous communication between the virus and the thief must occur. However, our priority is to prevent further data theft.

As the virus targets containers with more data, it always seeks neighboring containers. It can travel in all 8 directions in its quest for infecting container with maximum data. If any of the 8 neighboring container has more data units, the virus moves there. Consequently, our strategy is to entice the virus into a storage unit containing dummy data. Also since data can be generated on the fly, assume that infinite amount of data can be fudged (made available) to lead and trap the virus into desired location.

Information about the virus's current location and the desired location, which is the dummy container, is known. Given our awareness of the data warehouse's size (M*N) and the data stored in the containers, we aim to determine the minimum data required to be produced to entice the virus to the dummy container.

Adding data consumes time, so identifying where to fudge how much data, is crucial. The goal is to trap the virus with minimum amount of fudged data.

Constraints
2 <= N, M <= 7

0 < Units of data in containers < 30

Input
First line consist of two integers separated by space representing M and N.

Next M lines, each contain N space separated integers, representing data units in the corresponding containers.

Next line consist of two space separated integers, indicating current location of the virus

Last line consists of two space separated integers, specifying the location of the dummy container where we want to entice the virus to.

Output
The smallest amount of overall data needed to be fudged to attract the virus to the dummy container.

Time Limit (secs)
1

Examples
input

4 4

1 2 3 4

5 6 7 8

9 10 11 12

13 14 15 16

2 2

4 1

output

5

Explanation

The virus is on container [2,2] and we have to bring it to container [4, 1]. The neighbouring containers of [2, 2] are [(1,1),(1,2),(1,3),(2,1),(2,3),(3,1),(3,2),(3,3)] having data of [1,2,3,5,7,9,10,11] units, respectively. Now we know that virus will move to container [3, 3] because it contains the maximum amount of data in its neighbourhood. However, we also know that from [3, 3] reaching [4, 1] is impossible. Hence we now need to fudge data.

We can fudge and add 3 units of data to [3,1] where already 9 units of data is present. After fudging, it will became 12. 12 units of data will make it the maximum in neighbourhood. The virus will now thus move to [3,1] .

Now the virus is on container [3,1], The neighbouring container of the virus are [(2,1),(2,2),(3,2),(4,1),(4,2)] having data of [5,6,10,13,14] units, respectively. we will add 2 units of data to [4,1] where already 13 units of data is present. Adding 2 unit data will make it 15. 15 units of data is the maximum in the neighbourhood. The virus will then, move to [4,1], our dummy container

A total of 3+2 = 5 units of data was required to be fudged to entice the virus to desired location.

Similarly, one more possiblities is [2,2]->[3,2]->[4,1] which also requires 2 + 3 = 5 units of data to be fudged, Hence output is 5.

Example 2

input

5 6

1 17 18 20 11 10

3 17 15 18 16 15

10 11 20 6 8 3

18 18 5 11 4 16

3 4 8 17 18 20

1 1

3 4

output

16

Explanation

We will add 1 unit of data to [2,2] so they virus will move there, Next we want to move it to [3,3] but it is already the maximum in its neighbourhood. So, no new data needs to be added. Next, 15 units of data is required to make [3,4] maximum. So 15 + 1 = 16.