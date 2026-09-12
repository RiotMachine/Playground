CREATE TABLE ticket (
    id         INTEGER PRIMARY KEY,
    user_email TEXT NOT NULL,
    category   TEXT NOT NULL,
    freetext   TEXT NOT NULL
) STRICT;