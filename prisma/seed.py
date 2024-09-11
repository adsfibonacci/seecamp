import sqlite3

DATABASE_FILE = 'prisma/dev.db'  # Adjust the path to your SQLite file

# Sample user credentials
users = [
    ('user1', 'password1'),
    ('user2', 'password2'),
    ('user3', 'password3'),
    ('user4', 'password4'),
    ('user5', 'password5'),
    ('user6', 'password6'),
    ('user7', 'password7'),
    ('user8', 'password8'),
    ('user9', 'password9'),
    ('user10', 'password10')
]

def create_table():
    with sqlite3.connect(DATABASE_FILE) as conn:
        cursor = conn.cursor()
        # Create table
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS User (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL UNIQUE,
            password TEXT NOT NULL
        )
        ''')
        conn.commit()
        print('Created Table')

def populate_database():
    with sqlite3.connect(DATABASE_FILE) as conn:
        cursor = conn.cursor()
        # Insert users
        cursor.executemany('INSERT INTO User (username, password) VALUES (?, ?)', users)
        conn.commit()
        print('Database populated successfully!')

if __name__ == '__main__':
    create_table()
    populate_database()
