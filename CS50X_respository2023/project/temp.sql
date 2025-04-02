CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,
    username TEXT NOT NULL UNIQUE,
    password TEXT NOT NULL
);

CREATE TABLE books (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,
    title TEXT NOT NULL,
    author TEXT
);

CREATE TABLE assign (
    user_id INTEGER NOT NULL,
    books_id INTEGER NOT NULL,
    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(books_id) REFERENCES books(id)
);

/*The following example demonstrates using the assign table:
    in reverse order it gets the user id, uses this id to get the book id from assign then finds the books with that user's related book id*/
SELECT title FROM books
    WHERE book_id = (SELECT books_id FROM assign
        WHERE user_id = (SELECT id FROM users WHERE username = "Rosie")
);
