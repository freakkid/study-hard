from sys import argv

script, user_name, job = argv
prompt = '>'
double_prompt = '>>'

print "Hi %s, a famous %s, I'm the %s script." % (user_name, job, script)
print "I'd like to ask you a few question."
print "Do you like me %s?" % user_name
likes = raw_input(prompt)

print "Where do you live %s?" %user_name
lives = raw_input(double_prompt)

print "What kind of computer do you have?"
computer = raw_input(double_prompt)

print """
Alright, so you said %r about liking me.
You live in %r.  Not sure where that is.
And you have a %r computer.  Nice.
""" % (likes, lives, computer)
