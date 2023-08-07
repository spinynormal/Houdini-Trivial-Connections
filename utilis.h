int edgenmr (int hedge){
    int vtxprim = vertexprim(0 , hedge); 
    int vtxpt = vertexprimindex(0 , hedge); 
    int edge = vertex( 0 , "edge" , vtxprim,vtxpt); 
    return edge; 
}

int hedgefromedge(int hedge){
    int vtxprim = vertexprim(0 , hedge); 
    int vtxpt = vertexprimindex(0 , hedge); 
    int src = vertex( 0 , "src" , vtxprim,vtxpt); 
    int dst = vertex( 0 , "dst" , vtxprim,vtxpt); 
    int newhedge = hedge_srcvertex(0,hedge); 
    return newhedge;
} 

void setvtxAttrib (int hedge;string attrib){

    int vtxprim = vertexprim(0 , hedge); 
    int vtxpt = vertexprimindex(0 , hedge); 
    setvertexattrib(0, attrib, vtxprim,vtxpt, 1 ); 

}


void sethedgeAattrib (int hedge;string attrib) {

       int flip  = hedge_nextequiv(0, hedge);
       setvtxAttrib(hedge,attrib );
       setvtxAttrib(flip,attrib );

}

int checkvtx(int hedge;string attrib){

    int vtxprim = vertexprim(0 , hedge); 
    int vtxpt = vertexprimindex(0 , hedge); 
    int inprimal = vertex( 0 , attrib , vtxprim,vtxpt); 

    if ( inprimal == 1) {

        return 1; 
    }
    else{
        return 0; 
    }

}

int checkhedge(int hedge;string attrib){

int edge = checkvtx(hedge,attrib);
int flip  = hedge_nextequiv(0, hedge);
int edgeflip = checkvtx(flip,attrib);

if (edge == 1 || edgeflip ==1){

    return 1;
}

else {

    return 0; 
}


}


int signs(int hedge){
    int vtxprim = vertexprim(0 , hedge); 
    int vtxpt = vertexprimindex(0 , hedge); 
    int sign = vertex( 0 , "sign" , vtxprim,vtxpt); 
    return sign;
} 


vector vectorhedge(int h ){

    int srca = hedge_srcpoint(0 , h); 
    int dsta = hedge_dstpoint(0, h);
    
    vector va = point( 0 , "P", srca); 
    vector vb = point( 0 , "P", dsta);  
    vector hedgesg = normalize(vb-va); 
    return hedgesg; 
    
}   

void visualize_vector(vector viz; int prim; string name) {


int primspts[]  = primpoints(0, prim) ; 
vector a = point( 0 , "P", primspts[0]);
vector b = point( 0 , "P", primspts[1]);
vector c = point( 0 , "P", primspts[2]);

vector center = (a+b+c) / 3.0; 

int pt = addpoint(0,center); 

setpointattrib(0, name, pt, viz);

}

void gram_schmidt(int prim; vector ei, ej){

int hedgeprim = primhedge(0, prim);
ei = vectorhedge(hedgeprim);

vector normal = prim( 0 , "N", prim); 

ej = cross(normal,ei ); 

}

