# TITLE: pocketLibrary.io
# VIDEO: https://www.youtube.com/watch?v=69-N9jJU4YA

### DESCRIPTION:
 #### PRODUCT
  pocketLibrary.io is a virtual book management software, which allows individuals to digitally store all of the books they own physically, in one place. They can add and remove from their library, then view these books in their bookshelf - with options to change what order they're sorted in and to count the total number of books. Additionally, a search bar enables users to look at all books by a particular author or, thanks to the use of wildcards, find the full title of a book by searching only the word(s)/phrase(s) they remember. Also, there is a help page new users can use to learn how to navigate the software and the title at the top of each page is a button that redirects to the homepage.
 #### CODE
  Behind the scenes, I decided to use Python (with Flask and Jinja) for the back-end and HTML (with CSS) for the front-end. I also used SQL, to store the library database. All HTML pages are stored in a templates folder, while the CSS stylesheet is within the static folder. The database and app.py are stored in the main Project folder, with requirements.txt and a temp.sql folder which was for personal note taking.
   With the help of the CS50 library, I used app.py to execute SQL commands based on events triggered by HTML forms. This enabled me to produce the bookshelf that users see - handling the addition, deletion, counting and sorting of books.
    The stylesheet was instrumental in the website's production, as it handles the layout of the bookshelf and overall user-friendly apperence.
     Within templates, multiple pages provide the user with instructions and/or options to customize their library and bookshelf. These include the essential 'index.html', deletion prompt page 'delete.html' and others.
 #### DECISIONS
   It took a while to decide how I would implement the bookshelf but eventually I realised I could use a table with one row that can grow and shrink in length. Each book is a table data HTML tag with jinja syntax looping through the digital library and adding another cell to the table. I later added a delete option within this, so users can individualy delete any book they want - with app.py able to recieve the book's information. Originally this depended on the book's title and author but I realised that some people may have multiple copies of the same book and implementing the delete option like this would result in all copies getting removed - so I changed to deleting using the unique id.
