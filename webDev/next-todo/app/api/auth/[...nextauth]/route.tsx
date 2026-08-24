import NextAuth from 'next-auth'
import CredentialsProvider from 'next-auth/providers/credentials'

let ID: number = 1
const USER: { id: string; email: string; password: string }[] = []

const handler = NextAuth({
  providers: [
    CredentialsProvider({
      name: 'Credentials',
      credentials: {
        username: { label: 'Username', type: 'text', placeholder: 'jsmith' },
        password: { label: 'Password', type: 'password' }
      },

      async authorize (credentials, req) {
        const username = credentials?.username
        const password = credentials?.password
        if (!username || !password) {
          return null
        }

        const existingUser = USER.find(
          u => u.email === username && u.password === password
        )
        if (existingUser) {
          if (existingUser.password === password) {
            return existingUser
          } else {
            return null
          }
        }
        const newUser = {
          id: String(ID++),
          email: username,
          password
        }
        USER.push(newUser);

        return newUser;
      }
    })
  ]
})

export { handler as GET, handler as POST }
