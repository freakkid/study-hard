import sqlite3

try:
    conn = sqlite3.connect("tt.db")
    cur = conn.cursor()
    cur.execute("select name from sqlite_master where type='table' order by name")
    print cur.fetchall()
except sqlite3.Error, e:
    print e
