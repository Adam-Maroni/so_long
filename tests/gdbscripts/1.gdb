define parray
	set $i = 0
	while $arg0[$i] != (void*)0
		print $arg0[$i]
		set $i = $i + 1
	end
end

define plist
	set $i = $arg0
	while ($i) != (void*)0
		print (char*)(($i)->content)
		set $i = $i->next
	end
end

b ft_is_closed_rectangle
#b testMain.c:30
run
