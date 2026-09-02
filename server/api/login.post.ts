export default defineEventHandler(async (event) => {
  const body = await readBody(event)
  const config = useRuntimeConfig(event)

  if (body.password === config.popoPassword) {
    setCookie(event, 'auth', 'authenticated', {
      path: '/',
      maxAge: 60 * 60 * 24 * 7,
      sameSite: 'lax',
    })
    return { success: true }
  }

  throw createError({
    statusCode: 401,
    statusMessage: 'Mot de passe incorrect,',
  })
})
