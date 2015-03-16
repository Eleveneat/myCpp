#1003. Hit or Miss

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

One very simple type of solitaire game known as "Hit or Miss" (also known as "Frustration," "Harvest," "Roll-Call," "Talkative", and "Treize") is played as follows: take a standard deck of 52 playing cards four sets of cards numbered 1 through 13 (suits do not matter in this game) which have been shuffled and start counting through the deck 1, 2, 3, . . . , and so on. When your count reaches 13, start over at 1. Each time you count, look at the top card of the deck and do one of two things: if the number you count matches the value of the top card, discard it from the deck; if it does not match it, move that card to the bottom of the deck. You win the game if you are able to remove all cards from the deck (which may take a very long time). A version of this game can be devised for two or more players. The first player starts as before with a 52 card deck, while the other players have no cards initially. As the first player removes cards from her deck, she gives them to the second player, who then starts playing the same game, starting at count 1. When that player gets a match, he passes his card to the third player, and so on. The last player discards matches rather than passing them to player 1. All players who have cards to play with perform the following 2-step cycle of moves in lockstep: 1. Each player says his or her current count value and checks for a match. If there is no match, the top card is moved to the bottom of the deck; otherwise it is passed to the next player (or discarded if this is the last player). 2. Each player except the first takes a passed card (if there is one) and places it at the bottom of his or her deck. These rules are repeated over and over until either the game is won (all the cards are discarded by the last player) or an unwinnable position is reached. If any player ever runs out of cards, he waits until he is passed a card and resumes his count from where he left off. (e.g., if player 3 passes his last card on a count of 7, he waits until he receives a card from player 2 and resumes his count with 8 at the beginning of the next 2-step cycle).

##Input

Input will consist of multiple input sets. The first line of the file will contain a single positive integer nindicating the number of input sets in the file. Each input set will be a single line containing 53 integers: the first integer will indicate the number of players in the game and the remaining 52 values will be the initial layout of the cards in the deck, topmost card first. These values will all lie in the range 1 . . . 13, and the number of players will lie in the range 1. . . 10.

##Output

For each input set, output the input set number (as shown below, starting with 1) and either the phrase "unwinnable" or a list showing the last card discarded by each player. Use a single blank to separate all outputs.

##Sample Input

2

4 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13

4 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1

##Sample Output

Case 1: 13 13 13 13

Case 2: unwinnable

##Tips
1. 第一个玩家拥有全部的52张牌，而其他的玩家暂时没有牌在手上
2. 每一个玩家各自报数，若报的数与牌堆顶上的牌数字相同即为match
3. 每个玩家各自报数，各自匹配； 也即是说，A报一个数并记住，比较牌堆顶上的牌，接着是B报自己的数，比较自己牌堆顶上的牌，以此下去
4. 报数均从1开始，若没有牌在手上则不报数，待至有牌在手上时将上次所报之数加一作为此次的报数
5. 若某个玩家（非最后一个玩家）匹配了一次，也就是说报得数跟牌堆上的数字一样时，将此牌放入下一个玩家的牌堆的最底层； 如果是最后一个玩家，则丢弃该张牌。 若玩家不匹配，也就是说报得数跟牌堆上的数字不一样时，将该牌放入自己牌堆的最底层