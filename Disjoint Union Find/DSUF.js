// JavaScript Implementaton of Disjoint-Set 

class DSUF {
    constructor(N) {
        this.parent = Array.from({ length: N }, (_, i) => i);        // declare the parent array having values from 0 to N
        this.rank = Array(N).fill(0);                                // declare the rank array having values equal to 0
    };

    find(x) {                                // find the parent of the node
        if(this.parent[x] != x) this.parent[x] = this.find(this.parent[x]);
        
        //return the parent of node x
        return this.parent[x];
    };

    makeUnion(u, v) {                        // set node under the parent having high rank
        
        //find the parent of both u and v
        const up = this.find(u), vp = this.find(v);

        // check if both node have same parents
        if(up == vp) return; 

        // check if rank of the parent of node v 
        // is greater than rank of parent of u 
        if(this.rank[up] < this.rank[vp]) {

            //set parent of up to parent of vp
            this.parent[up] = this.parent[vp];

            // increment the rank of vp
            this.rank[vp] += this.rank[up];
        } else {
            // set parent of vp to parent of up
            this.parent[vp] = this.parent[up];

            //increment the rank of up
            this.rank[up] += this.rank[vp];
        };
    };

    isUnion(u, v) {                          // check whether u and v are having same parent or not

        // find the parent of u and v
        const up = this.find(u), vp = this.find(v);

        // check if parents of both nodes
        // are equal
        if(up == vp) { 
            return "Yes";
        } else {
            return "No";
        };
    };
};

// driver code
var dsuf = new DSUF(10);     
dsuf.makeUnion(1,2);
dsuf.makeUnion(3,2);
dsuf.makeUnion(1,6);
dsuf.makeUnion(5,7);

const ans1 = dsuf.isUnion(1, 2);
console.log(ans1);
const ans2 = dsuf.isUnion(1, 7);
console.log(ans2);
