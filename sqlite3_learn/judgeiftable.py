import sqlite3

conn = sqlite3.connect("tt.db")
#try:
create_tb_cmd = '''
CREATE TABLE IF NOT EXISTS USER
(NAME TEXT,
AGE INT,
SALARY REAL);
'''
conn.execute(create_tb_cmd)
#except:
#    print "Ceate table failed!"
insert_cmd = '''
INSERT INTO USER (NAME,AGE,SALARY) VALUES ("Rocky",10,20.1);
'''
conn.execute(insert_cmd)
cur = conn.execute("SELECT NAME,AGE,SALARY from USER")
for row in cur:
    print "NAME = ", row[0]
    print "AGE = ", row[1]
    print "SALARY = ", row[2]

print "sdf"
conn.commit()
conn.close()
    
