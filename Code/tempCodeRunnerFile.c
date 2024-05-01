for(int x=1;x<n;x++){
            for(int y=1;y<n-x && p[y].at <= p[i].ct;y++){
                if(p[y].bt > p[y+1].bt ){
                    swap(&p[y],&p[y+1]);
                }
            }
        }