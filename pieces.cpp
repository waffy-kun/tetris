#include <iostream>

char mPieces[7 /* types */]
            [4 /* rotations */]
            [5 /* horizontal blocks */]
            [5 /* vertical blocks */] = {
                //Square
                {
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    }
                },
                //I-shape
                {
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {1, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    }
                },
                //L-shape
                {
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    }
                },
                //Mirrored L-shape
                {
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0}
                    }
                },
                //N-shape
                {
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    }
                },
                //Mirrored N-shape
                {
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    },
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                    }
                },

            };