<h2>Technical Specification</h2>
<hr>
<strong>Creation of new character</strong>

In the beginning you have three choices, to start a new game, to start a saved game and to exit. 
The saved games, it is just option that we may add to game in the future. 
It will save information of every main character that is created before in the game.
When you choose the first one you should create main character for the game with maximum hp, hp, name, attack, experience, level, gold.
Then main character can choose what to do next. There are 7 choices. Notice that in every selection has option going back or quit.

<strong>1.Map:</strong>  
Where he can go to some cities to struggle with other strong characters, 
Firstly, there is a country. Here you will choose the city, then also enemies in cities. 
And if you win the enemy, main character will level up, gain experience and gold. 
Also, you can take the weapons of enemy by adding to inventory.

<strong>2.Inventory:</strong>  
Shows inventory of character.  And character can store only best 3 items. 
Also, each item has damage, depending on this damage the price will increase. Item from inventory increases total damage of a character.

<strong>3.Statistics:</strong>  
Shows statistics. It’s just showing information about main character. HP, gold, damage and other stuff.

<strong>4.Shop:</strong>   
Here character can buy weapon by his golds. As written before inventory can store only 3 items.

<strong>5.Work:</strong>   
By working he can earn the golds. It doesn’t have any job, character just works and getting money.

<strong>6.Go home:</strong>  
go home to relax and restore hp. 

<strong>7.Quit:</strong>  
Exit from a game

<h2>Classes:</h2>
<hr>
<strong>Application:</strong>     <br>    
Application it is a class where all logic located. Main menu, fighting and other stuff.

<strong>Character:</strong>  
Character is class which stores information and methods of characters. Information like hp, damage and other.
Methods like add item to inventory, show Statistics, check if we may level up, etc.

<strong>Item:</strong>   
It’s information about weapon. We store fields like name, damage, and price.

<strong>Country:</strong>  
In this class we store a name of country and a list of cities.

<strong>City:</strong>   
In the city we store name and citizens just like in country class, also there are a method to show information about city and add citizens to it.


<h2>Codes:</h2>   
<hr>
You can find all codes in this repository

<h2>Provide 4 screenshots:</h2>   
<hr>
<p align="center">
  <img src="imgs/log1.jpeg" width="350" >
  <img src="imgs/stats1.png" width="350" >
</p>

<p align="center">
  <img src="imgs/log2.png" width="350" >
  <img src="imgs/stats2.png" width="350" >
</p>
<hr>
<h3>Bonus: work with git and upload files to Github, have at least 3 commits. Provide link</h3>
<h3>Done✓</h3>
<hr>
<h3>Bonus: apply Design patterns: MVC, SOLID, or others</h3>  
<h3>Done✓</h3>
<hr>
<h3>Bonus: suggest future improvement for your game in 3 sentences</h3>  
<h3>Done✓</h3>
<hr>
<h3>Advanced: implement “Random thought” feature (anytime while game is running you can hear “Random though” of the main character), consider parallel thread</h3>  
<h3>Done✓</h3>
<hr>
