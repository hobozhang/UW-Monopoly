Building Buyer 7000
===

Compilation:
---

###Environment Requirement:

g++ complier 4.2 or above

X environment (graphic display only)

To have only text display:

1. cp textMakefile Makefile
2. make

To have graphic display:
	
1. cp graphicMakefile Makefile
2. make

Command list
---

A player’s turn starts when the previous player inputs 'next', and the game prints 'Your Name's turn'. During your turn there are the following commands available:

(in your own turn):

1. roll: roll dice and move forward, note that players can only roll once in a turn. However, the player may choose to roll at any time during the turn (before ‘next’).
2. next: end your turn and pass on to the next player in position.
3. save <filename>: a player should choose to save the game after his is done with his actions but before keying in ‘next’. The savefile will be stored in the save folder, and when game resumes, it will starts with the next player in line.
4. improve <property’s name> buy/sell: this command gives you the ability to buy/sell upgrades. Note that a player can choose to buy/sell any property under his/her name multiple times, however the player cannot buy after the property reaches level 5 nor can the player sell after the property is at level 0.
5. trade  <player’s full name>  <give>  <receive>: the trade function allows players to trade properties and money mutually. The <player’s full name> should be the full name of the player you wish to trade with and  <give> /<receive> represents what you hope to offer/accept for the trade. Note that a player can only trade with existing player’s in the game and the give/receive must be valid (not exceeding money balance, owned and un-mortgaged properties).
6. mortgage/unmortgage: a player can choose to mortgage any owned unmortgaged proeprties under his/her name. The player will receive 50 percent of the worth in cash and expected to pay 60 percent in cash when attempting to unmortgage the mortgaged proeprties.
7. assets: print the player’s all current assets including cash and owned properties.
8. bankrupt: declare bankrupt and transfer all assets (cash and properties) to the debtor (another player or the bank)

(out of your turn):

1. In various situations, you may be prompted a question. At your own wisdom, you should give the response in the format specified in the question. For example: “do you wish to unmortgage the property right now? (y/n)”, keying in ‘y’ means yes and ‘n’ for no.