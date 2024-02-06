struct list { struct list *next; T data; };
typedef struct list ** list_t;

/*@ inductive linked{L}(struct list *bl,
                        struct list *el,
                        \list<struct list*> ll) {
  case linked_ll_nil{L}:
    \forall struct list *el; linked{L}(el, el, \Nil);
  case linked_ll_cons{L}:
    \forall struct list *bl, *el,
      \list<struct list*> tail;  \separated(bl, el)
      ==> \valid(bl) ==> linked{L}(bl->next, el, tail)
      ==> separated_from_list(bl, tail)
      ==> linked{L}(bl, el, \Cons(bl, tail));
  } */


/*@ inductive linked_n{L}(struct list *root,
                          struct list *bound,
                          struct list **cArr,
                          integer index, integer n) {
    case linked_n_bound{L}:
      \forall struct list **cArr, *bound, integer index; 0 <= index <= MAX_SIZE
      ==> linked_n(bound, cArr, index, 0, bound);
    case linked_n_cons{L}:
      \forall struct list *root, **cArr, *bound, integer index, n; 0 < n ==> 0 <= index
        ==> 0 <= index + n <= MAX_SIZE
        ==>	\valid(root) ==> root == cArr[index]
        ==> linked_n(root->next, cArr, index + 1, n - 1, bound)
        ==> linked_n(root, cArr, index, n, bound);
  } */
