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

define pmlximg
	printf "img = %p\n", $arg0->img
	printf "addr = %p\n", $arg0->addr
	printf "bits_per_pixel = %d\n", $arg0->bits_per_pixel
	printf "line_length = %d\n", $arg0->line_length
	printf "endian = %d\n", $arg0->endian
end

define pmlxdata
	printf "mlx= %p\n",$arg0->mlx
	printf "mlx_win= %p\n",$arg0->mlx_win
	printf "img= %p\n",$arg0->img
	pmlximg $arg0->img
end


b ft_player_move_up
run
