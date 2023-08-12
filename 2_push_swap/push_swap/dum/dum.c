// void	greedy(t_push_swap *ps)
// {
// 	int				target;
// 	int				future;
// 	int				flag;
// 	int				f;
// 	int				cnt_rb;
// 	int				cnt_rrb;
// 	t_deque_node	*tmp;

// 	target = ps->sum;
// 	while (target > 0)
// 	{
// 		future = target - 1;
// 		flag = 0;
// 		cnt_rb = 0;
// 		cnt_rrb = 1;
// 		tmp = ps->b.node[REAR];
// 		while (tmp->idx != target)
// 		{
// 			tmp = tmp->prev;
// 			cnt_rb++;
// 		}
// 		tmp = ps->b.node[FRONT];
// 		while (tmp->idx != target)
// 		{
// 			tmp = tmp->next;
// 			cnt_rrb++;
// 		}
// 		if (cnt_rb + 1 > cnt_rrb)
// 		{
// 			while (cnt_rrb > 0)
// 			{
// 				if (ps->b.node[REAR]->idx == future && flag < 2)
// 				{
// 					--future;
// 					++flag;
// 					pa(ps);
// 					ra(ps);
// 				}
// 				rrb(ps);
// 				cnt_rrb--;
// 			}
// 		}
// 		else
// 		{
// 			while (cnt_rb > 0)
// 			{
// 				f = 0;
// 				if (ps->b.node[REAR]->idx == future && flag < 2)
// 				{
// 					--future;
// 					++flag;
// 					++f;
// 					pa(ps);
// 					ra(ps);
// 				}
// 				if (f == 0)
// 					rb(ps);
// 				cnt_rb--;
// 			}
// 		}
// 		pa(ps);
// 		target -= flag + 1;
// 		if (flag == 1)
// 			rra(ps);
// 		else if (flag == 2)
// 		{
// 			while (flag-- > 0)
// 				rra(ps);
// 			if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
// 				sa(ps);
// 		}
// 	}
// }

// void	partitioning(t_push_swap *ps, int base)
// {
// 	int	pivot[2];

// 	pivot[0] = ps->a.size / 3;        // 33
// 	pivot[1] = ps->a.size - pivot[0]; // 67
// 	while (ps->a.size > pivot[0])
// 	{
// 		if (ps->a.node[REAR]->idx > pivot[1] + base) // L 68 ~ 100 (33개)
// 			ra(ps);
// 		else if (ps->a.node[REAR]->idx <= pivot[1] + base) // M  34 ~ 67 (33개)
// 		{
// 			pb(ps);
// 			if (ps->b.node[REAR]->idx <= pivot[0] + base) // S   1 ~ 33 (33개)
// 				rb(ps);
// 		}
// 	}
// 	if (ps->a.size > 0)
// 		partitioning(ps, pivot[1] + base);
// }
