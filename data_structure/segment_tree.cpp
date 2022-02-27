const int N = 10 + 1e5;
ll I = 0, n, q, arr[N], seg[4*N];
ll function(ll left, ll right){
	return left + right;
}

ll build(int idx, int l, int r){
	ll &node = seg[idx];
	ll mid = l +( (r - l)/2);
	if (r == l) return node = arr[l];
	if ((r < l) ) return I;
	ll right = build((idx*2)+1, mid+1, r);
	ll left = build(idx*2, l, mid);
	return node = function(left, right);
}

ll sum(int idx, int l, int r, int l1, int r1){
	ll mid = (l1 + (r1 - l1)/2);
	if (r1 < l1) return I;
	if ((l1 > r) || (r1 < l)) 
		return I; 
	
	if (((l1 >= l) && (l1 <= r)) && ((r1 >= l) && (r1 <= r))) 
		return seg[idx];
	ll right = sum((idx*2)+1, l, r, mid+1, r1);
	ll left = sum(idx*2, l, r, l1, mid);
	return function(left, right);
}

void update(int idx, int l, int r, int xIdx, int xVal){
	int mid = (l + (r - l)/2);
	ll &node = seg[idx];
	if ((r == l) && (l == xIdx)) {
		node = xVal;
		return ;
	}
	if (r < l) return;
	if ((l > xIdx) || (r < xIdx)) 
		return ;
	update(idx*2, l, mid, xIdx, xVal);
	update((idx*2) + 1, mid+1, r, xIdx, xVal);
	node = function(seg[idx*2], seg[(idx*2)+1]);
}
