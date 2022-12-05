import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# figure init
fig=plt.figure()


# mmesh init
N, M = (40,40)
mesh = np.random.rand(N,M)
mesh=np.rint(mesh).astype('int')
#mesh[5,5] = 1
#mesh[6,5] = 1
#mesh[7,5] = 1


plt.imshow(mesh)

frames = [[plt.imshow(mesh,animated=True)]]
# animate function
def animate(k,mesh=mesh,N=N,M=M):
    for i in range(0,k):
        mesh = evolve_gol(mesh,N,M)
        #plt.imshow(mesh)
        frames.append([plt.imshow(mesh,animated=True)])
    return mesh


# mesh evolution function
def evolve_gol(mesh,N,M):
    new = mesh.copy()
    for i in range(1,N-1):
        for j in range(1,M-1):
            dude = mesh[i,j]
            neighbors = [mesh[k,l] for k in range(i-1,i+2) for l in range(j-1,j+2)]
            alive = sum(neighbors) - dude
            match dude:
                case 1:
                    if alive == 2 or alive == 3:
                        new[i,j] = 1
                    else:
                        new[i,j] = 0
                case 0:
                    if  alive == 3:
                        new[i,j] = 1
                    else:
                        new[i,j] = 0
    mesh = new.copy()
    return mesh

animate(50)

# actual animation
anim = animation.ArtistAnimation(fig,frames,interval=500)
plt.show()
anim.save("gol.mp4")
