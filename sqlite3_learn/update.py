#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('T.db')
print 'Opened database successfully';

conn.execute("UPDATE COMPANY set NAME = 'UNS' ,ID = 1000,    SALARY = 25000.00 where ID=1")
conn.commit
print "Total number of rows updated :", conn.total_changes

cursor = conn.execute("SELECT id, name, address, salary from COMPANY")
for row in cursor:
    print "ID = ", row[0]
    print "NAME = ", row[1]
    print "ADDRESS = ", row[2]
    print "SALARY = ", row[3], "\n"

print "Operation done successfully";
conn.close()


