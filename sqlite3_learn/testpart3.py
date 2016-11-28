#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('part3.db')
print "Opened part3.db successfully";

conn.execute('''CREATE TABLE IF NOT EXISTS NOTE
         (USER_NAME TEXT  NOT NULL,
          NOTE_NAME TEXT  NOT NULL,
          NOTE_CONTENT TEXT NOT NULL);''')

print "Table created successful"

conn.execute("""INSERT INTO NOTE 
            (USER_NAME,NOTE_NAME,NOTE_CONTENT)
            VALUES ('UNS','a','wozaidengni')""");

conn.execute("""INSERT INTO NOTE 
            (USER_NAME,NOTE_NAME,NOTE_CONTENT)
            VALUES ('UNS','b','wozaidengni')""");

conn.execute("""INSERT INTO NOTE 
            (USER_NAME,NOTE_NAME,NOTE_CONTENT)
            VALUES ('UNS_2.0','a','wozaidengni')""");

conn.execute("""INSERT INTO NOTE 
            (USER_NAME,NOTE_NAME,NOTE_CONTENT)
            VALUES ('UNS_3.0','a','wozaidengni')""");

conn.execute("""INSERT INTO NOTE 
            (USER_NAME,NOTE_NAME,NOTE_CONTENT)
            VALUES ('UNS_4.0','a','wozaidengni')""");

conn.commit()
         
cursor = conn.execute("SELECT USER_NAME,NOTE_NAME,NOTE_CONTENT from NOTE")

for row in cursor:
    print "username = ", row[0]
    print "notename = ", row[1]
    print "notecontent = ", row[2]

print "Done!"

conn.execute("DELETE from NOTE where USER_NAME='UNS' AND NOTE_NAME='a';")
conn.commit()
print "Delete!"

cursor = conn.execute("SELECT USER_NAME,NOTE_NAME,NOTE_CONTENT from NOTE")

for row in cursor:
    print "username = ", row[0]
    print "notename = ", row[1]
    print "notecontent = ", row[2]

print "Done!"





