"use client"

import axios from 'axios'
import { useEffect, useState } from 'react'

export default function UserCard () {
  const [user, setUser] = useState({})

  useEffect(() => {
    axios
      .get(
        'https://week-13-offline.kirattechnologies.workers.dev/api/v1/user/details'
      )
      .then(response => {
        setUser(response.data)
      })
  })

  if(!user) {
    return(
      <div>
        Loading...
      </div>
    )
  }

  return <div>
    {user.name}
  </div>
}
